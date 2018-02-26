#include <iostream>
#include <vector>
#include <set>
#include <map>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,directedS,no_property,property<edge_weight_t,int> > Graph;
typedef graph_traits<Graph>::edge_descriptor Edge;

typedef property_map<Graph, edge_weight_t>::type WeightMap;

struct road{
	int from;
	int to;
	int length;
	bool river;
};

int solve(int n,int m, int k, int x, int y, vector<road>& roads){

	int t = n*(k+1);
	Graph G(t);
	WeightMap wm=get(edge_weight,G);

	int i,j;
	for(i=0;i<m;i++){
		int from = roads[i].from;
		int to = roads[i].to;
		int len = roads[i].length;
		if(roads[i].river){
			for(j=0;j<k;j++){
				Edge e;
				tie(e,tuples::ignore)=add_edge(from,to+n,G);
				wm[e]=len;
				tie(e,tuples::ignore)=add_edge(to,from+n,G);
				wm[e]=len;
				from+=n;
				to+=n;
			}
			Edge e;
			tie(e,tuples::ignore)=add_edge(from,to,G);
			wm[e]=len;
			tie(e,tuples::ignore)=add_edge(to,from,G);
			wm[e]=len;
		}else{
			for(j=0;j<=k;j++){
				Edge e;
				tie(e,tuples::ignore)=add_edge(from,to,G);
				wm[e]=len;
				tie(e,tuples::ignore)=add_edge(to,from,G);
				wm[e]=len;
				from+=n;
				to+=n;
			}
		}
	}

	vector<int> dist(t);

	dijkstra_shortest_paths(G,x,distance_map(make_iterator_property_map(dist.begin(),get(vertex_index,G))));

	return dist[y+k*n];
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n,m,k,x,y;
		cin>>n>>m>>k>>x>>y;

		vector<road> roads(m);
		int i;

		for(i=0;i<m;i++){
			cin>>roads[i].from;
			cin>>roads[i].to;
			cin>>roads[i].length;
			cin>>roads[i].river;
		}
		cout<<solve(n,m,k,x,y,roads)<<endl;
	}
}