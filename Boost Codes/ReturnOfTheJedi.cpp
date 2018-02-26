#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS, no_property, 
		property<edge_weight_t, int> > Graph;

typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::edge_iterator EdgeIt;
typedef graph_traits<Graph>::out_edge_iterator OutEdgeIt;

typedef property_map<Graph, edge_weight_t>::type WeightMap;

void dfs(int src,vector<bool>& visited, Graph& T, WeightMap& wm, vector<int>& costs, int maxedge){
	costs[src]=maxedge;
	OutEdgeIt ei,oeiend;
	for(tie(ei,oeiend)=out_edges(src,T); ei!=oeiend;ei++){
		int e = max(maxedge,wm[*ei]);
		Vertex v = target(*ei,T);
		if(!visited[v]){
			visited[v]=true;
			dfs(v,visited,T,wm,costs,e);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,i;
		cin>>n>>i;

		Graph G(n);
		WeightMap weightmap = get(edge_weight,G);

		int j,k;
		for(j=0;j<n-1;j++){
			for(k=j+1;k<n;k++){
				int w;
				cin>>w;
				Edge e;
				tie(e,tuples::ignore) = add_edge(j,k,G);
				weightmap[e]=w;
			}
		}

		vector<Edge> mst;
		kruskal_minimum_spanning_tree(G,back_inserter(mst));
		long long mstcost=0;

		Graph T(n);
		WeightMap wm = get(edge_weight,T);

		for(auto it = mst.begin();it!=mst.end();it++){
			Edge e;
			Vertex u = source(*it,G);
			Vertex v = target(*it,G);

			tie(e,tuples::ignore) = add_edge(u,v,T);
			int cost = weightmap[*it];
			wm[e]=cost;
			mstcost+=cost;
		}

		vector<vector<int> > maxedge(n);
		for(j=0;j<n;j++){
			vector<int> costs(n,0);
			vector<bool> visited(n,false);
			visited[j]=true;
			dfs(j,visited,T,wm,costs,0);
			maxedge[j]=costs;
		}
		long long newmstcost = numeric_limits<long long>::max();
		
		EdgeIt ebeg,eend;
		for(tie(ebeg,eend)=edges(G); ebeg!=eend;ebeg++){
			Vertex u = source(*ebeg,G);
			Vertex v = target(*ebeg,G);

			if(edge(u,v,T).second)
				continue;
			int delta = weightmap[*ebeg]-maxedge[u][v];
			newmstcost = min(newmstcost,delta+mstcost);
		}
		cout<<newmstcost<<endl;
	}
}