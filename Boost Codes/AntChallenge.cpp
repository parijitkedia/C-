#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;


typedef adjacency_list<vecS,vecS,undirectedS,
no_property,
property<edge_weight_t,int> > Graph;
typedef graph_traits<Graph>:: edge_descriptor Edge;
typedef graph_traits<Graph>:: edge_iterator EdgeIt;
typedef graph_traits<Graph>:: vertex_descriptor Vertex;
typedef property_map<Graph, edge_weight_t>:: type WeightMap;

struct triple{
	int from;
	int to;
	int weight;
};

int solve(int t, int e, int s, int a, int b, vector<vector<triple> >& weights, vector<int>& hives){
	Graph g(t);
	WeightMap ws = get(edge_weight,g);
	int i,j;
	for(i=0;i<s;i++){
		Graph gi(t);
		WeightMap wm=get(edge_weight,gi);
		for(j=0;j<e;j++){
			triple edge = weights[i][j];
			Edge ed;
			tie(ed,tuples::ignore)=add_edge(edge.from,edge.to,gi);
			wm[ed]=edge.weight;
		}

		vector<Edge> mst;
		kruskal_minimum_spanning_tree(gi,back_inserter(mst));
		vector<Edge>::iterator ebeg,eend=mst.end();
		for(ebeg=mst.begin();ebeg!=eend;ebeg++){
			Edge ge;
			tie(ge,tuples::ignore)=add_edge(source(*ebeg,gi),target(*ebeg,gi),g);
			ws[ge]=wm[*ebeg];
		}
	} 

	int vertices = num_vertices(g);
	vector<int> dist(vertices);
	vector<int> pred(vertices);
	dijkstra_shortest_paths(g,a,predecessor_map(make_iterator_property_map(pred.begin(),get(vertex_index,g))).
		distance_map(make_iterator_property_map(dist.begin(),get(vertex_index,g))));

	return dist[b];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int t,e,s,a,b;
		cin>>t>>e>>s>>a>>b;
		vector<vector<triple> > ws(s);

		int i,j;
		for(i=0;i<e;i++){
			triple eg;
			cin>>eg.from>>eg.to;
			for(j=0;j<s;j++){
				cin>>eg.weight;
				ws[j].push_back(eg);
			}
		}
		vector<int> hs;
		for(i=0;i<s;i++){
			int h;
			cin>>h;
			hs.push_back(h);
		}
		cout<<solve(t,e,s,a,b,ws,hs)<<endl;
	}
}
