#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor,
property <edge_weight_t, long> > > > > Graph; 

typedef property_map<Graph, edge_capacity_t>::type      EdgeCapacityMap;
typedef property_map<Graph, edge_weight_t >::type       EdgeWeightMap; 
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type       ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor          Vertex;
typedef graph_traits<Graph>::edge_descriptor            Edge;
typedef graph_traits<Graph>::out_edge_iterator  OutEdgeIt;

struct EdgeAdder {
	EdgeAdder(Graph &G, EdgeCapacityMap &capacitymap, EdgeWeightMap &weightmap, ReverseEdgeMap &revedgemap) 
	: G(G), capacitymap(capacitymap), weightmap(weightmap), revedgemap(revedgemap) {}
	void addEdge(int u, int v, long c, long w) {
		Edge e, rev_e;
		tie(e, tuples::ignore) = add_edge(u, v, G);
		tie(rev_e, tuples::ignore) = add_edge(v, u, G);
		capacitymap[e] = c;
        weightmap[e] = w; // new!
        capacitymap[rev_e] = 0;
        weightmap[rev_e] = -w; // new
        revedgemap[e] = rev_e; 
        revedgemap[rev_e] = e; 
    }
    Graph &G;
    EdgeCapacityMap &capacitymap;
    EdgeWeightMap &weightmap;
    ReverseEdgeMap  &revedgemap;
};

int main(){
	int t;
	cin>>t;

	while(t--){
		int b,s,p;
		cin>>b>>s>>p;

		int N = b+s+3;
		int source = N-1;
		int target = N-2;
		int collect = N-3;

		Graph G(N);
		EdgeCapacityMap capacitymap = get(edge_capacity, G);
		EdgeWeightMap weightmap = get(edge_weight, G);
		ReverseEdgeMap revedgemap = get(edge_reverse, G);
		ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, G);
		EdgeAdder ea(G, capacitymap, weightmap, revedgemap);

		vector<int> cost(p);
		vector<pair<int,int> > comb(p);

		int i,maxv=0;
		for(i=0;i<p;i++){
			int bi,si,c;
			cin>>bi>>si>>c;
			maxv=max(c,maxv);
			comb[i]=make_pair(bi,si+b);
			cost[i]=c;
		}

		for(i=0;i<p;i++){
			ea.addEdge(comb[i].first,comb[i].second,1,maxv-cost[i]);
		}

		for(i=0;i<b;i++){
			ea.addEdge(source,i,1,0);
			ea.addEdge(i,collect,1,maxv);
		}
		ea.addEdge(collect,target,b,0);

		for(i=b;i<b+s;i++){
			ea.addEdge(i,target,1,0);
		}

		int flow = push_relabel_max_flow(G,source,target);
		successive_shortest_path_nonnegative_weights(G,source,target);
		int cost1 = find_flow_cost(G);

		cout<<maxv*flow - cost1<<endl;
	}
}