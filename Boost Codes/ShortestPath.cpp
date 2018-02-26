#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, directedS,
no_property,
property<edge_weight_t,int> > Graph;

typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

typedef property_map<Graph,edge_weight_t>:: type WeightMap;

int main(){
	ios_base::sync_with_stdio(false);
	int t=1;
	while(t--){
		int n,m,q;
		cin>>n>>m>>q;

		int i;
		int lat,lon;
		for(i=0;i<n;i++){
			cin>>lat>>lon;
		}

		Graph G(n);
		WeightMap weightmap = get(edge_weight,G);
		for(i=0;i<m;i++){
			Vertex a,b;
			int c;
			cin>>a>>b>>c;

			Edge e;
			bool success;
			tie(e,success)=add_edge(a,b,G);
			weightmap[e]=c;
		}

		for(i=0;i<q;i++){
			int s,t;
			cin>>s>>t;
			vector<int> dist(n);
			Vertex start=s;
			dijkstra_shortest_paths(G,start,distance_map(make_iterator_property_map(dist.begin(),get(vertex_index,G))));
			
			if(dist[t]<INT_MAX)
				cout<<dist[t]<<endl;
			else
				cout<<"unreachable"<<endl;
		}
	}
}