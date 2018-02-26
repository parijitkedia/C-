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
typedef graph_traits<Graph>::edge_iterator EdgeIt;

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

struct loc{
	int g;
	int d;
};

struct path{
	int from;
	int to;
	int mincap;
	int maxcap;
};

bool solve(int l,int p, vector<loc> locs, vector<path> paths){
	Graph g(l);
	EdgeCapacityMap capacity = get(edge_capacity, g);
	ReverseEdgeMap revedgemap = get(edge_reverse, g);
	ResidualCapacityMap rescapacitymap = get(edge_residual_capacity, g);	
	EdgeAdder ea(g,capacity,revedgemap);

	Vertex source=add_vertex(g);
	Vertex target=add_vertex(g);

	int i;
	long sumavail=0,sumreq=0;
	
	vector<int> avail,req;

	for(i=0;i<l;i++){
		loc& ll = locs[i];
		avail.push_back(ll.g);
		req.push_back(ll.d);
		sumavail+=ll.g;
		sumreq+=ll.d;
	}
	if(sumavail<sumreq)
		return false;

	int reqflow=sumreq;
	
	for(i=0;i<p;i++){
		path& pp = paths[i];
		ea.addEdge(pp.from,pp.to,pp.maxcap-pp.mincap);
		
		avail[pp.to]+=pp.mincap;
		req[pp.from]+=pp.mincap;
		reqflow+=pp.mincap;
	}

	for(i=0;i<l;i++){
		//loc& ll = locs[i];
		ea.addEdge(source,i,avail[i]);
		ea.addEdge(i,target,req[i]);
	}

	int flow = push_relabel_max_flow(g,source,target);

	if(flow>=reqflow){
		return true;
	}else{
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int l,p;
		cin>>l>>p;
		vector<loc> ls;
		int i;
		for(i=0;i<l;i++){
			int g,d;
			cin>>g>>d;
			loc ll;
			ll.g=g;
			ll.d=d;
			ls.push_back(ll);
		}

		vector<path> ps;
		for(i=0;i<p;i++){
			int f,t,minc,maxc;
			cin>>f>>t>>minc>>maxc;
			path pt;
			pt.from=f;
			pt.to=t;
			pt.mincap=minc;
			pt.maxcap=maxc;
			ps.push_back(pt);
		}
		if(solve(l,p,ls,ps)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}