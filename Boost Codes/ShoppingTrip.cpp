#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor> > > > Graph;
 // Interior Property Maps
typedef property_map<Graph, edge_capacity_t>::type EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

struct EdgeAdder {
	EdgeAdder(Graph & G, EdgeCapacityMap &capacity, ReverseEdgeMap &rev_edge)
	: G(G), capacity(capacity), rev_edge(rev_edge) {}
	void addEdge(int u, int v, long c) {
		Edge e, reverseE; bool success;
		tie(e, success) = add_edge(u, v, G);
		tie(reverseE, success) = add_edge(v, u, G);
		capacity[e] = c;
		capacity[reverseE] = 0;
		rev_edge[e] = reverseE;
		rev_edge[reverseE] = e;
	}
	Graph &G;
	EdgeCapacityMap &capacity;
	ReverseEdgeMap  &rev_edge;
};

struct street{
	int from;
	int to;
};

bool solve(int n,int m,int s,vector<int>& ss, vector<street>& sts){
	Graph G(n);
	EdgeCapacityMap capacity = get(edge_capacity, G);
	ReverseEdgeMap revedgemap = get(edge_reverse, G);
	EdgeAdder ea(G,capacity,revedgemap);

	Vertex source = add_vertex(G);
	Vertex target = add_vertex(G);

	ea.addEdge(source,0,s);

	int i;
	for(i=0;i<s;i++){
		ea.addEdge(ss[i],target,1);
	}

	for(i=0;i<m;i++){
		ea.addEdge(sts[i].from,sts[i].to,1);
		ea.addEdge(sts[i].to,sts[i].from,1);
	}

	int flow = push_relabel_max_flow(G,source,target);
	return flow==s;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m,s;
		cin>>n>>m>>s;

		vector<int> ss(s);
		int i;
		for(i=0;i<s;i++){
			cin>>ss[i];
		}

		vector<street> sts;
		for(i=0;i<m;i++){
			street st;
			cin>>st.from>>st.to;
			sts.push_back(st);
		}
		bool ans = solve(n,m,s,ss,sts);
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}