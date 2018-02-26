/*
    Max-Cost Max-Flow problem.
    Subtract costs from MAX_COST (100 in this case) to transform problem to Min-Cost Max-Flow.
    Model the graph as a biparted graph with links between buyers and sites. Capacity = 1, cost = MAX_COST - cost.
    Connect each site to its state. Capacity = state_capacity, cost = MAX_COST.
    Connect source to all buyers. Capacity = 1, cost = MAX_COST.
    Connect all states to sink. Capacity = state_capacity, cost = MAX_COST
*/

// Includes
// ========
// STL includes
#include <iostream>
#include <cstdlib>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

// BGL Graph definitions
// ===================== 
// Graph Type with nested interior edge properties for Cost Flow Algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> Traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, Traits::edge_descriptor,
                boost::property <boost::edge_weight_t, long> > > > > Graph; // new!
// Interior Property Maps
typedef boost::property_map<Graph, boost::edge_capacity_t>::type      EdgeCapacityMap;
typedef boost::property_map<Graph, boost::edge_weight_t >::type       EdgeWeightMap; // new!
typedef boost::property_map<Graph, boost::edge_residual_capacity_t>::type ResidualCapacityMap;
typedef boost::property_map<Graph, boost::edge_reverse_t>::type       ReverseEdgeMap;
typedef boost::graph_traits<Graph>::vertex_descriptor          Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor            Edge;
typedef boost::graph_traits<Graph>::out_edge_iterator  OutEdgeIt; // Iterator

// Custom Edge Adder Class, that holds the references
// to the graph, capacity map, weight map and reverse edge map
// ===============================================================
class EdgeAdder {
    Graph &G;
    EdgeCapacityMap &capacitymap;
    EdgeWeightMap &weightmap;
    ReverseEdgeMap  &revedgemap;

public:
    EdgeAdder(Graph &G, EdgeCapacityMap &capacitymap, EdgeWeightMap &weightmap, ReverseEdgeMap &revedgemap) 
        : G(G), capacitymap(capacitymap), weightmap(weightmap), revedgemap(revedgemap) {}

    void addEdge(int u, int v, long c, long w) {
        Edge e, rev_e;
        boost::tie(e, boost::tuples::ignore) = boost::add_edge(u, v, G);
        boost::tie(rev_e, boost::tuples::ignore) = boost::add_edge(v, u, G);
        capacitymap[e] = c;
        weightmap[e] = w; // new!
        capacitymap[rev_e] = 0;
        weightmap[rev_e] = -w; // new
        revedgemap[e] = rev_e; 
        revedgemap[rev_e] = e; 
    }
};

int T, n, m, s, c, src, sink, flow, bid, state;
Graph G;
int MAX_COST = 100;

void read_build_graph(){
    // build Graph
    std::cin >> n >> m >> s;

    G = Graph(n + m + s + 2); 
    src = n + m + s; sink = src + 1;

    EdgeCapacityMap capacitymap = boost::get(boost::edge_capacity, G);
    EdgeWeightMap weightmap = boost::get(boost::edge_weight, G);
    ReverseEdgeMap revedgemap = boost::get(boost::edge_reverse, G);
    ResidualCapacityMap rescapacitymap = boost::get(boost::edge_residual_capacity, G);
    EdgeAdder eaG(G, capacitymap, weightmap, revedgemap);

    for(int i=0;i<s;i++){
        std::cin >> c;
        eaG.addEdge(n + m + i, sink, c, MAX_COST);
    }

    for(int i=0;i<m;i++){
        std::cin >> state; state--;
        eaG.addEdge(n + i, n + m + state, 1, MAX_COST);
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            std::cin >> bid;
            eaG.addEdge(i, n + j, 1, MAX_COST - bid);
        }

        eaG.addEdge(src, i, 1, MAX_COST);
    }
}


void solve(){
    
    long flow = push_relabel_max_flow(G, src, sink);
    boost::successive_shortest_path_nonnegative_weights(G, src, sink);
    int cost = boost::find_flow_cost(G);

    std::cout << flow << " " << flow * MAX_COST * 4 - cost << std::endl; // 4 is the path length from source to sink for each unit of flow
}

void testcase(){
    read_build_graph();
    solve();
}

// Main
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin >> T;
    while(T--) testcase();
    return 0;
}