#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, directedS,
no_property, property<edge_weight_t, int>> 			Graph;
typedef graph_traits<Graph>::edge_descriptor		Edge;	

typedef property_map<Graph, edge_weight_t>::type	WeightMap;

int k_index(int i,int j){
	return i*(i+1)/2 + j;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int k;
		cin>>k;

		int V = k*(k+1)/2;

		vector<vector<int> > v(k);
		int i,j;
		for(i=0;i<k;i++){
			for(j=0;j<=i;j++){
				int a;
				cin>>a;
				v[i].push_back(a);
			}
		}

		Graph G(V);
		WeightMap weightmap = get(edge_weight, G);
		Edge e;	bool success;

		for(i=0;i<k;i++){
			for(j=0;j<=i;j++){
				if(j<i){
					tie(e,success)=add_edge(k_index(i,j),k_index(i,j+1),G);
					weightmap[e]=v[i][j];
					tie(e,success)=add_edge(k_index(i,j+1),k_index(i,j),G);
					weightmap[e]=v[i][j+1];
				}
				if(i<k-1){
					tie(e,success)=add_edge(k_index(i,j),k_index(i+1,j),G);
					weightmap[e]=v[i][j];
					tie(e,success)=add_edge(k_index(i,j),k_index(i+1,j+1),G);
					weightmap[e]=v[i][j];
					tie(e,success)=add_edge(k_index(i+1,j),k_index(i,j),G);
					weightmap[e]=v[i+1][j];
					tie(e,success)=add_edge(k_index(i+1,j+1),k_index(i,j),G);
					weightmap[e]=v[i+1][j+1];
				}
			}
		}

		vector<int> d11(V);
		dijkstra_shortest_paths(G, k_index(0,0),distance_map(make_iterator_property_map(d11.begin(), get(vertex_index, G))));

		vector<int> dk1(V);
		dijkstra_shortest_paths(G, k_index(k-1,0),distance_map(make_iterator_property_map(dk1.begin(), get(vertex_index, G))));

		vector<int> dkk(V);
		dijkstra_shortest_paths(G, k_index(k-1,k-1),distance_map(make_iterator_property_map(dkk.begin(), get(vertex_index, G))));

		int minv=INT_MAX;
		for(i=0;i<k;i++){
			for(j=0;j<=i;j++){
				int id = k_index(i,j);
				minv = min(minv, v[i][j]+d11[id]+dk1[id]+dkk[id]);
			}
		}
		cout<<minv<<endl;
	}
}