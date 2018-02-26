#include <iostream>
#include <vector>
#include <cmath>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor> > > > 		Graph;

typedef property_map<Graph, edge_capacity_t>::type 				EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type 	ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type 				ReverseEdgeMap;
typedef graph_traits<Graph>::vertex_descriptor 					Vertex;
typedef graph_traits<Graph>::edge_descriptor 					Edge;


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

long solve(int n,int m,int k,int l,vector<int>& ps, vector<int>& ph,vector<pair<int,int> >& pts){

	Graph g(2*n);
	EdgeCapacityMap capacity = get(edge_capacity, g);
	ReverseEdgeMap revedgemap = get(edge_reverse, g);
	ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, g);	
	EdgeAdder ea(g,capacity,revedgemap);

	Vertex source = add_vertex(g);
	Vertex target = add_vertex(g);

	int i;
	for(i=0;i<k;i++){
		ea.addEdge(source,ps[i],1);
		ea.addEdge(ps[i]+n,target,1);
	}

	for(i=0;i<l;i++){
		ea.addEdge(ph[i],ph[i]+n,1);
	}

	for(i=0;i<m;i++){
		ea.addEdge(pts[i].first,pts[i].second,INT_MAX);
		ea.addEdge(pts[i].first+n,pts[i].second+n,1);
	}

	long flow = push_relabel_max_flow(g,source,target);
	return flow;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,l;
		cin>>n>>m>>k>>l;

		vector<int> ps(n);
		int i;
		for(i=0;i<k;i++){
			cin>>ps[i];
		}

		vector<int> ph(l);
		for(i=0;i<l;i++){
			cin>>ph[i];
		}

		vector<pair<int,int> > pts(m);
		for(i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			pts[i]=make_pair(u,v);
		}
		cout<<solve(n,m,k,l,ps,ph,pts)<<endl;
	}
}