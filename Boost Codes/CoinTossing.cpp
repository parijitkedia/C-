#include <iostream>
#include <vector>
#include <cmath>

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

struct game{
	int p1;
	int p2;
	int o;
};

bool solve(int n,int m, vector<game>& games, vector<int>& scores){

	int i;
	int sum=0;

	for(i=0;i<n;i++){
		sum+=scores[i];
	}

	if(sum!=m)
		return false;

	vector<int> left(scores);
	for(i=0;i<m;i++){
		game& gg = games[i];

		switch(gg.o){
			case 0: continue;
			case 1: --left[gg.p1];
					break;
			case 2: --left[gg.p2];
					break;
		}
	}

	for(i=0;i<n;i++){
		if(left[i]<0)
			return false;
	}

	Graph G;
	EdgeCapacityMap capacity = get(edge_capacity, G);
	ReverseEdgeMap revedgemap = get(edge_reverse, G);
	EdgeAdder ea(G,capacity,revedgemap);

	Vertex source = add_vertex(G);
	Vertex target = add_vertex(G);

	vector<Vertex> pnode(n);
	vector<Vertex> gnode(m);

	for(i=0;i<n;i++){
		pnode[i]=add_vertex(G);
	}

	for(i=0;i<m;i++){
		gnode[i]=add_vertex(G);
	}

	for(i=0;i<m;i++){
		ea.addEdge(source,gnode[i],1);
	}

	for(i=0;i<m;i++){
		game& gg = games[i];
		Vertex gn = gnode[i];
		Vertex p1 = pnode[gg.p1];
		Vertex p2 = pnode[gg.p2];

		switch(gg.o){
			case 0: ea.addEdge(gn,p1,1);
					ea.addEdge(gn,p2,1);
					break;
			case 1: ea.addEdge(gn,p1,1);
					break;
			case 2: ea.addEdge(gn,p2,1);
					break;
		}
	}

	for(i=0;i<n;i++){
		ea.addEdge(pnode[i],target,scores[i]);
	}

	int flow = push_relabel_max_flow(G,source,target);
	return flow==sum;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		int i;
		vector<game> gs(m);
		for(i=0;i<m;i++){
			cin>>gs[i].p1;
			cin>>gs[i].p2;
			cin>>gs[i].o;
		}

		vector<int> ss(n);
		for(i=0;i<n;i++){
			cin>>ss[i];
		}

		bool ans = solve(n,m,gs,ss);
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}