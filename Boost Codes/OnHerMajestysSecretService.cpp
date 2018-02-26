#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,directedS,
no_property,
property<edge_weight_t,int> > Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef	graph_traits<Graph>::edge_iterator EdgeIt;

typedef property_map<Graph,edge_weight_t>::type WeightMap;

struct slopeski{
	char w;
	int x;
	int y;
	int z;
};

int solve(int n,int m,int a,int s,int c,int d,vector<slopeski>& ss, vector<int>& agt, vector<int>& sht){
	Graph G(n);

	WeightMap wm = get(edge_weight,G);
	int i,j,k;
	for(i=0;i<m;i++){
		Edge e;
		slopeski& sls = ss[i];
		
		tie(e,tuples::ignore) = add_edge(sls.x,sls.y,G);
		wm[e]=sls.z;

		if(sls.w=='L'){
			tie(e,tuples::ignore) = add_edge(sls.y,sls.x,G);
			wm[e]=sls.z;
		}
	}

	vector<vector<int> > distmap(a,vector<int>(n));
	for(i=0;i<a;i++){
		dijkstra_shortest_paths(G,agt[i],distance_map(make_iterator_property_map(distmap[i].begin(),get(vertex_index,G))));
	}

	vector<vector<int> > T(a,vector<int>(s));
	for(i=0;i<s;i++){
		for(j=0;j<a;j++){
			T[j][i]=distmap[j][sht[i]];
		}
	}

	int low=0,high=INT_MAX;
	while(low<high){
		int mid = low + (-low+high)/2;

		Graph GG(a + c*s);
		for(i=0;i<a;i++){
			for(j=0;j<s;j++){
				if(T[i][j]==INT_MAX)
					continue;
				for(k=0;k<c;k++){
					if(T[i][j] + (k+1)*d <=mid)
						add_edge(i,a+k*s+j,GG);
				}
			}
		}

		vector<Vertex> matemap(a+c*s);
		edmonds_maximum_cardinality_matching(GG,make_iterator_property_map(matemap.begin(),get(vertex_index,GG)));

		Vertex null = graph_traits<Graph>::null_vertex();
		int size=0;
		for(i=0;i<a;i++){
			size+=matemap[i]!=null;
		}
		if(size==a)
			high=mid;
		else
			low=mid+1;
	}
	return low;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,a,s,c,d;
		cin>>n>>m>>a>>s>>c>>d;

		int i;
		vector<slopeski> ss(m);
		for(i=0;i<m;i++){
			cin>>ss[i].w;
			cin>>ss[i].x;
			cin>>ss[i].y;
			cin>>ss[i].z;
		}

		vector<int> agt(a);
		for(i=0;i<a;i++){
			cin>>agt[i];
		}

		vector<int> sht(s);
		for(i=0;i<s;i++){
			cin>>sht[i];
		}
		cout<<solve(n,m,a,s,c,d,ss,agt,sht)<<endl;
	}
}

