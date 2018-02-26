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

int solve(int w,int n,vector<pair<int,int> >& bricks){
	Graph g;
	EdgeCapacityMap capacity = get(edge_capacity, g);
	ReverseEdgeMap revedgemap = get(edge_reverse, g);
	EdgeAdder ea(g,capacity,revedgemap);

	int i,t = 2*w;
	vector<Vertex> points(t);
	for(i=0;i<t;i++){
		points[i]=add_vertex(g);
	}

	for(i=1;i<w;i++){
		ea.addEdge(points[2*i-1],points[2*i],1);
	}

	for(i=0;i<n;i++){
		int l = bricks[i].first;
		int r = bricks[i].second;

		l=2*l;
		r=2*r-1;

		ea.addEdge(points[l],points[r],1);
	}

	int flow = push_relabel_max_flow(g,points[0],points[2*w-1]);
	return flow;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int w,n;
		cin>>w>>n;
		vector<pair<int,int> > bs(n);
		int i;
		for(i=0;i<n;i++){
			int l,r;
			cin>>l>>r;
			bs[i]=make_pair(min(l,r),max(l,r));
		}
		cout<<solve(w,n,bs)<<endl;
	}
}