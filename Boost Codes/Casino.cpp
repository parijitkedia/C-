#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
    property<edge_capacity_t, long,
        property<edge_residual_capacity_t, long,
            property<edge_reverse_t, Traits::edge_descriptor,
                property <edge_weight_t, long>>>>> 			Graph;

typedef property_map<Graph, edge_capacity_t>::type 			EdgeCapacityMap;
typedef property_map<Graph, edge_weight_t>::type 			EdgeWeightMap;
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type 			ReverseEdgeMap;
typedef graph_traits<Graph>::edge_descriptor 				Edge;
typedef graph_traits<Graph>::vertex_descriptor 				Vertex;

struct EdgeAdder {
	EdgeAdder(Graph &G, EdgeCapacityMap &capacitymap, EdgeWeightMap &weightmap, ReverseEdgeMap &revedgemap)
			: G(G), capacitymap(capacitymap), weightmap(weightmap), revedgemap(revedgemap) {}
	void addEdge(int u, int v, long c, long w) {
		Edge e, reverseE;
		tie(e, tuples::ignore) = add_edge(u, v, G);
		tie(reverseE, tuples::ignore) = add_edge(v, u, G);
		capacitymap[e] = c;
		weightmap[e] = w;
		capacitymap[reverseE] = 0;
		weightmap[reverseE] = -w;
		revedgemap[e] = reverseE;
		revedgemap[reverseE] = e;
	}
	Graph &G;
	EdgeCapacityMap &capacitymap;
	EdgeWeightMap &weightmap;
	ReverseEdgeMap &revedgemap;
};

struct mission{
	int x;
	int y;
	int q;
};

int solve(int n,int m,int l, vector<mission>& ms){

	Graph G(n);
    EdgeCapacityMap capacitymap = get(edge_capacity, G);
    EdgeWeightMap weightmap = get(edge_weight, G);
    ReverseEdgeMap revedgemap = get(edge_reverse, G);
    ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
    EdgeAdder ea(G, capacitymap, weightmap, revedgemap);

	Vertex source = add_vertex(G);
	Vertex target = add_vertex(G);

	ea.addEdge(source,0,l,0);
	ea.addEdge(n-1,target,l,0);

	int i;
	int max=128;
	for(i=0;i<n-1;i++){
		ea.addEdge(i,i+1,l,max);
	}

	for(i=0;i<m;i++){
		mission& m = ms[i];
		ea.addEdge(m.x,m.y,1,(m.y-m.x)*max - m.q);
	}

	int flow = push_relabel_max_flow(G,source,target);

	successive_shortest_path_nonnegative_weights(G,source,target);
	int cost = find_flow_cost(G);

	return flow*max*(n-1) - cost;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,l;
		cin>>n>>m>>l;

		int i;
		vector<mission> ms(m);
		for(i=0;i<m;i++){
			cin>>ms[i].x;
			cin>>ms[i].y;
			cin>>ms[i].q;
		}
		cout<<solve(n,m,l,ms)<<endl;
	}
}