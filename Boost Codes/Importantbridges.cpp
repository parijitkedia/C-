#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/biconnected_components.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,undirectedS,
		no_property,
		property<edge_name_t,int> > Graph;

typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef	graph_traits<Graph>::edge_iterator EdgeIt;

typedef property_map<Graph,edge_name_t>::type ComponentMap;

struct bridge{
	int from;
	int to;
};

void solve(int n,int m, vector<bridge>& bs){
	Graph G(n);

	int i;
	for(i=0;i<m;i++){
		add_edge(bs[i].from,bs[i].to,G);
	}

	ComponentMap componentmap = get(edge_name,G);
	int num = biconnected_components(G,componentmap);

	vector<int> compsize(num);
	EdgeIt ebeg,eend;
	for(tie(ebeg,eend)=edges(G);ebeg!=eend;ebeg++){
		compsize[componentmap[*ebeg]]++;
	}

	vector<pair<int,int> > bridges;

	for(tie(ebeg,eend)=edges(G);ebeg!=eend;ebeg++){
		if(compsize[componentmap[*ebeg]]==1){
			int u = source(*ebeg,G);
			int v = target(*ebeg,G);
			bridges.push_back(make_pair(min(u,v),max(u,v)));
		}
	}

	sort(bridges.begin(),bridges.end());

	cout<<bridges.size()<<endl;

	for(i=0;i<bridges.size();i++){
		cout<<bridges[i].first<<" "<<bridges[i].second<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		vector<bridge> bs;
		int i;
		for(i=0;i<m;i++){
			bridge b;
			cin>>b.from;
			cin>>b.to;
			bs.push_back(b);
		}
		solve(n,m,bs);
	}
}