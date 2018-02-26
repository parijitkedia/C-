#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace boost;
using namespace std;

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor> > > > 			Graph;

typedef property_map<Graph, edge_capacity_t>::type 					EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type			ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type 					ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor 						Vertex;
typedef graph_traits<Graph>::edge_descriptor 						Edge;

struct EdgeAdder {
	EdgeAdder(Graph & G, EdgeCapacityMap &capacity, ReverseEdgeMap &rev_edge)
	: G(G), capacity(capacity), rev_edge(rev_edge) {}
	void addEdge(int u, int v, long c) {
		Edge e, reverseE;
		tie(e, tuples::ignore) = add_edge(u, v, G);
		tie(reverseE, tuples::ignore) = add_edge(v, u, G);
		capacity[e] = c;
		capacity[reverseE] = 0;
		rev_edge[e] = reverseE;
		rev_edge[reverseE] = e;
	}
	Graph &G;
	EdgeCapacityMap &capacity;
	ReverseEdgeMap  &rev_edge;
};

int main(){

	int t;
	cin>>t;

	while(t--){
		int z,j;
		cin>>z>>j;

		vector<int> cost(z);
		int i;
		for(i=0;i<z;i++){
			cin>>cost[i];
		}

		vector<int> reward(j);
		int total=0;
		for(i=0;i<j;i++){
			cin>>reward[i];
			total+=reward[i];
		}

		int jof=z;
		int source = z+j;
		int target=source+1;

		Graph G(z+j+2);
		EdgeCapacityMap capacity = get(edge_capacity, G);
		ReverseEdgeMap revedgemap = get(edge_reverse, G);
		EdgeAdder ea(G,capacity,revedgemap);

		for(i=0;i<z;i++){
			ea.addEdge(i,target,cost[i]);
		}

		for(i=0;i<j;i++){
			ea.addEdge(source,jof+i,reward[i]);
		}

		int k;
		for(i=0;i<j;i++){
			int a;
			cin>>a;
			for(k=0;k<a;k++){
				int c;
				cin>>c;
				ea.addEdge(jof+i,c,numeric_limits<int>::max());
			}
		}

		int res = push_relabel_max_flow(G,source,target);
		cout<<total-res<<endl;
	}
}