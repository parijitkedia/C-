#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

using namespace boost;
using namespace std;

typedef adjacency_list_traits<vecS, vecS, directedS> 				Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor,
property <edge_weight_t, long> > > > > 				Graph;

typedef property_map<Graph, edge_capacity_t>::type      			EdgeCapacityMap;
typedef property_map<Graph, edge_weight_t >::type       			EdgeWeightMap;
typedef property_map<Graph, edge_residual_capacity_t>::type 		ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type       			ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor         				Vertex;
typedef graph_traits<Graph>::edge_descriptor           				Edge;
typedef graph_traits<Graph>::out_edge_iterator  					OutEdgeIt; 
typedef graph_traits<Graph>::edge_iterator							EdgeIt;	


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

pair<int,int> solve(int n,int m,int s,vector<int>& limits, vector<int>& states, vector<vector<int> >& bids){

	int t = n+m;
	int maxbid=0;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			maxbid=max(maxbid,bids[i][j]);
		}
	}

	Graph g(t+s+2);
	EdgeCapacityMap capacity = get(edge_capacity,g);
	EdgeWeightMap weight = get(edge_weight,g);
	ReverseEdgeMap rev_edge = get(edge_reverse,g);

	EdgeAdder ea(g,capacity,weight,rev_edge);

	int source = n+m+s;
	int target = source+1;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			ea.addEdge(i,j+n,1,maxbid-bids[i][j]);
		}
		ea.addEdge(source,i,1,0);
	}

	for(i=0;i<m;i++){
		ea.addEdge(i+n,n+m+states[i],1,0);
	}

	for(i=0;i<s;i++){
		ea.addEdge(n+m+i,target,limits[i],0);
	}

	int flow = push_relabel_max_flow(g,source,target);
	successive_shortest_path_nonnegative_weights(g,source,target);
	int cost=find_flow_cost(g);

	return make_pair(flow,flow*maxbid-cost);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,s;
		cin>>n>>m>>s;

		vector<int> ls(s);
		int i,j;
		for(i=0;i<s;i++){
			cin>>ls[i];
		}

		vector<int> ss(m);
		for(i=0;i<m;i++){
			cin>>ss[i];
			ss[i]--;
		}

		vector<vector<int> > bs(n,vector<int>(m));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>bs[i][j];
			}
		}

		pair<int,int> sol = solve(n,m,s,ls,ss,bs);
		cout<<sol.first<<" "<<sol.second<<endl;
	}
}