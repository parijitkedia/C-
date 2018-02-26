// Includes
// ========
// STL includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>

// BGL Graph definitions
// =====================
typedef	boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> Traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
	boost::property<boost::edge_capacity_t, long,
		boost::property<boost::edge_weight_t, int,
			boost::property<boost::edge_residual_capacity_t, long,
				boost::property<boost::edge_reverse_t, Traits::edge_descriptor> > > > >	Graph;
// Interior Property Maps
typedef	boost::property_map<Graph, boost::edge_capacity_t>::type		EdgeCapacityMap;
typedef	boost::property_map<Graph, boost::edge_residual_capacity_t>::type	ResidualCapacityMap;
typedef	boost::property_map<Graph, boost::edge_reverse_t>::type		ReverseEdgeMap;
typedef boost::property_map<Graph, boost::edge_weight_t>::type	LengthMap;
typedef	boost::graph_traits<Graph>::vertex_descriptor			Vertex;
typedef	boost::graph_traits<Graph>::edge_descriptor			Edge;


using namespace boost;
typedef adjacency_list<vecS, vecS, undirectedS,no_property,property<edge_weight_t, int,
    boost::property<boost::edge_capacity_t, long> > >	            Graph_sp;
typedef	boost::graph_traits<Graph_sp>::edge_descriptor			Edge_sp;
    
typedef boost::property_map<Graph_sp, boost::edge_weight_t>::type	WeightMap_sp;
typedef	boost::property_map<Graph_sp, boost::edge_capacity_t>::type EdgeCapacityMap_sp;
typedef graph_traits<Graph_sp>::edge_iterator		EdgeIt_sp;		// to iterate over all edges



// Custom Edge Adder Class, that holds the references
// to the graph, capacity map and reverse edge map
// ===================================================
class EdgeAdder {
	Graph &G;
	EdgeCapacityMap	&capacitymap;
	ReverseEdgeMap	&revedgemap;

public:
	// to initialize the Object
	EdgeAdder(Graph & G, EdgeCapacityMap &capacitymap, ReverseEdgeMap &revedgemap):
		G(G), capacitymap(capacitymap), revedgemap(revedgemap){}

	// to use the Function (add an edge)
	void addEdge(int from, int to, long capacity) {
		Edge e, rev_e;
		bool success;
		boost::tie(e, success) = boost::add_edge(from, to, G);
		boost::tie(rev_e, success) = boost::add_edge(to, from, G);
		capacitymap[e] = capacity;
		capacitymap[rev_e] = 0; // reverse edge has no capacity!
		revedgemap[e] = rev_e;
		revedgemap[rev_e] = e;
	}
};

int main() {
	int T; std::cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m, s, f;
        std::cin >> n >> m >> s >> f;

        Graph_sp G1(n);
        WeightMap_sp weightmap_sp = get(edge_weight, G1);
        EdgeCapacityMap_sp capacitymap_sp = boost::get(boost::edge_capacity, G1);

		
		for (int i = 0; i < m; i++) {
			// read in roads
			int beginning, end, cap, length;
            std::cin >> beginning >> end >> cap >> length;
            Edge_sp e;	bool success;
            tie(e, success) = add_edge(beginning, end, G1);	
            weightmap_sp[e] = length;
            capacitymap_sp[e] = cap;
		}
		
        

        std::vector<Vertex> predmap_from_start(n);	
        std::vector<int> distmap_from_start(n);		
        std::vector<Vertex> predmap_from_end(n);	
        std::vector<int> distmap_from_end(n);		
        Vertex start = s;
        dijkstra_shortest_paths(G1, start, // We MUST provide at least one of the two maps
            predecessor_map(make_iterator_property_map(predmap_from_start.begin(), get(vertex_index, G1))).	// predecessor map as Named Parameter
            distance_map(make_iterator_property_map(distmap_from_start.begin(), get(vertex_index, G1))));	// distance map as Named Parameter
        start = f;
        dijkstra_shortest_paths(G1, start, // We MUST provide at least one of the two maps
            predecessor_map(make_iterator_property_map(predmap_from_end.begin(), get(vertex_index, G1))).	// predecessor map as Named Parameter
            distance_map(make_iterator_property_map(distmap_from_end.begin(), get(vertex_index, G1))));	// distance map as Named Parameter
        //std::cout << "both shortest paths calculated" << std::endl;
        //std::cout << "f - s : " << distmap_from_end[s] << std::endl;
        //std::cout << "s - f : " << distmap_from_start[f] << std::endl;
        
        int shortest_path = distmap_from_start[f];

        Graph G(n);	// creates an empty graph on n vertices
		EdgeCapacityMap capacitymap = boost::get(boost::edge_capacity, G);
		ReverseEdgeMap revedgemap = boost::get(boost::edge_reverse, G);
		ResidualCapacityMap rescapacitymap = boost::get(boost::edge_residual_capacity, G);
		EdgeAdder eaG(G, capacitymap, revedgemap);
		

        
        EdgeIt_sp ebeg, eend;
        for (tie(ebeg, eend) = edges(G1); ebeg != eend; ++ebeg) {	// edges(G) returns a pair of iterators which define a range of all edges. 
            // For undirected graphs, each edge is visited once, with some orientation.
            // ebeg is EdgeIterator, *ebeg is EdgeDescriptor
            Vertex u = source(*ebeg, G);
            Vertex v = target(*ebeg, G);
            int len = weightmap_sp[*ebeg];
            if(distmap_from_start[u] > distmap_from_start[v]){
                // swap u and v
                int tmp = u;
                int tmp2 = v;
                u = tmp2;
                v = tmp;
            }
            if(distmap_from_start[u] + len + distmap_from_end[v] == shortest_path) {
                // add edge to new graph
                int cap = capacitymap_sp[*ebeg];
                //std::cout << "adding edge from " << u << " - " << v << "with len " << len << "and capacity " << cap <<std::endl;
                eaG.addEdge(u, v, cap);
            }
    
        }

        int flow = boost::push_relabel_max_flow(G, s, f);
        std::cout << flow << std::endl;
	}
}