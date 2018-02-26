#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,undirectedS,
no_property,
property<edge_weight_t,int> > Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef	graph_traits<Graph>::edge_iterator EdgeIt;

typedef property_map<Graph,edge_weight_t>::type WeightMap;

struct triple{
	int from;
	int to;
	int weight;
};

int solve(int n,int e,int s,int a,int b,vector<vector<triple> >&ws, vector<int>& hs){
	
	Graph G(n);
	WeightMap weightmap = get(edge_weight,G);

	int i,j;
	for(i=0;i<s;i++){
		Graph GR(n);
		WeightMap wm = get(edge_weight,GR);
		for(j=0;j<e;j++){
			triple edge=ws[i][j];
			Edge e;
			tie(e,tuples::ignore)=add_edge(edge.from,edge.to,GR);
			wm[e]=edge.weight;
		}
		vector<Edge> mst;
		kruskal_minimum_spanning_tree(GR,back_inserter(mst));
		vector<Edge>::iterator ebeg,eend=mst.end();
		for(ebeg=mst.begin();ebeg!=eend;ebeg++){
			Edge e;
			tie(e,tuples::ignore)=add_edge(source(*ebeg,GR),target(*ebeg,GR),G);
			weightmap[e]=wm[*ebeg];
		}
	}

	int vertices = num_vertices(G);
	vector<int> dist(vertices);
	vector<int> pred(vertices);

	dijkstra_shortest_paths(G,a,distance_map(make_iterator_property_map(dist.begin(),get(vertex_index,G))));

	return dist[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,e,s,a,b;
		cin>>n>>e>>s>>a>>b;

		int i,j;
		vector<vector<triple> > ws(s);
		for(i=0;i<e;i++){
			triple eg;
			cin>>eg.from>>eg.to;
			for(j=0;j<s;j++){
				cin>>eg.weight;
				ws[j].push_back(eg);
			}
		}

		vector<int> hs(s);
		for(i=0;i<s;i++){
			cin>>hs[i];
		}
		cout<<solve(n,e,s,a,b,ws,hs)<<endl;
	}
}