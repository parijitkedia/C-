#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/tuple/tuple.hpp>

using namespace boost;
using namespace std;

typedef adjacency_list<vecS, vecS, undirectedS,
no_property,
property<edge_weight_t,int> > Graph;

typedef graph_traits<Graph>::edge_descriptor Edge;

typedef property_map<Graph,edge_weight_t>::type WeightMap;

pair<int,int> solve(Graph G){
	
	WeightMap wm = get(edge_weight,G);
	vector<Edge> mst;
	kruskal_minimum_spanning_tree(G,back_inserter(mst));

	vector<Edge>::iterator ebeg,eend=mst.end();
	int sum=0;
	for(ebeg=mst.begin();ebeg!=eend;ebeg++){
		sum+=wm[*ebeg];
	}

	int vertices = num_vertices(G);
	vector<int> dist(vertices);

	dijkstra_shortest_paths(G,0,distance_map(make_iterator_property_map(dist.begin(),get(vertex_index,G))));

	int maxval=0;
	int i;
	for(i=0;i<vertices;i++){
		maxval=max(maxval,dist[i]);
	}
	return make_pair(sum,maxval);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		Graph G(n);
		WeightMap weightmap = get(edge_weight,G);
		int i;
		for(i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;

			Edge e;
			tie(e,tuples::ignore) = add_edge(u,v,G);
			weightmap[e]=w;
		}

		pair<int,int> sol = solve(G);
		cout<<sol.first<<" "<<sol.second<<endl;
	}
}