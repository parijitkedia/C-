#include <iostream>
#include <vector>
#include <algorithm>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/strong_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, directedS,
	no_property,
	property<edge_weight_t,int> > Graph;
typedef graph_traits<Graph>:: vertex_descriptor Vertex;
typedef graph_traits<Graph>:: edge_descriptor Edge;
typedef graph_traits<Graph>:: edge_iterator EdgeIt;

typedef property_map<Graph,edge_weight_t>:: type WeightMap;

void testcases(){
	int V,E,t;

	cin>>V>>E>>t;
	Graph G(V);

	WeightMap weightmap = get(edge_weight,G);
	for(int i=0;i<E;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Edge e; bool success;
		tie(e,success) = add_edge(v,u,G);
		weightmap[e] = w;
	}

	vector<Vertex> sccmap(V);
    int nscc = strong_components(G,
                make_iterator_property_map(
                      sccmap.begin(),get(vertex_index,G)));

    vector<int> is_max(nscc,1);
    EdgeIt ebeg,eend;
    for(tie(ebeg,eend)=edges(G);ebeg!=eend;++ebeg){
    	Vertex u = source(*ebeg,G);
   		Vertex v = target(*ebeg,G);
   		if(sccmap[u]!=sccmap[v])
   			is_max[sccmap[u]]=0;
    }

    int max_count = count(is_max.begin(),is_max.end(),true);
    if(max_count!=1){
    	cout<<"NO"<<endl;
    	return;
    }

    vector<int> distmap(V);
    vector<Vertex> predmap(V);
    dijkstra_shortest_paths(G,t,
    	predecessor_map(make_iterator_property_map(predmap.begin(),get(vertex_index,G))).
    	distance_map(make_iterator_property_map(distmap.begin(),get(vertex_index,G))));

    int res=INT_MAX;
    for(int u=0;u<V;u++){
    	if(is_max[sccmap[u]]){
    		res = min(res,distmap[u]);
    	}
    }
    cout<<res<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		testcases();
	}
	return 0;
}
