#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>
// Namespaces
using namespace boost;
using namespace std;

typedef adjacency_list_traits<vecS, vecS, directedS> 				Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor,
property <edge_weight_t, long> > > > > 				Graph;
// Interior Property Maps
typedef property_map<Graph, edge_capacity_t>::type      			EdgeCapacityMap;
typedef property_map<Graph, edge_weight_t >::type       			EdgeWeightMap;
typedef property_map<Graph, edge_residual_capacity_t>::type 		ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type       			ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor         				Vertex;
typedef graph_traits<Graph>::edge_descriptor           				Edge;

struct EdgeAdder {
	EdgeAdder(Graph & G, EdgeCapacityMap &capacity, EdgeWeightMap &weight, ReverseEdgeMap &rev_edge)
	: G(G), capacity(capacity), weight(weight), rev_edge(rev_edge) {}
	void addEdge(int u, int v, long c, long w) {
		Edge e, reverseE;
		tie(e, tuples::ignore) = add_edge(u, v, G);
		tie(reverseE, tuples::ignore) = add_edge(v, u, G);
		capacity[e] = c;
		weight[e] = w;
		capacity[reverseE] = 0;
		weight[reverseE] = -w;
		rev_edge[e] = reverseE;
		rev_edge[reverseE] = e;
	}
	Graph &G;
	EdgeCapacityMap &capacity;
	EdgeWeightMap &weight;
	ReverseEdgeMap  &rev_edge;
};

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		Graph G(n);

		EdgeCapacityMap capacitymap = get(edge_capacity, G);
		EdgeWeightMap weightmap = get(edge_weight, G);
		ReverseEdgeMap revedgemap = get(edge_reverse, G);
		ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
		
		EdgeAdder ea(G, capacitymap, weightmap, revedgemap);

		Vertex source = add_vertex(G);
		Vertex target = add_vertex(G);

		int i;
		for(i=0;i<n;i++){
			int a,c;
			cin>>a>>c;
			ea.addEdge(source,i,a,c);
		}

		int ctr=0;
		for(i=0;i<n;i++){
			int s,p;
			cin>>s>>p;
			ctr+=s;
			ea.addEdge(i,target,s,20-p);
		}

		for(i=0;i<n-1;i++){
			int v,e;
			cin>>v>>e;
			ea.addEdge(i,i+1,v,e);
		}

		int flow = push_relabel_max_flow(G,source,target);
		successive_shortest_path_nonnegative_weights(G,source,target);
		long cost = find_flow_cost(G);

		if(flow>=ctr)
			cout<<"possible"<<" ";
		else
			cout<<"impossible"<<" ";
		cout<<flow<<" "<<-cost + flow*20<<endl;
	}
}