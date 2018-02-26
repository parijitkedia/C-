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

typedef adjacency_list<vecS, vecS, undirectedS,
no_property,
property<edge_weight_t,int> > Graph;

typedef graph_traits<Graph>:: edge_descriptor Edge;
typedef graph_traits<Graph>:: edge_iterator EdgeIt;

typedef property_map<Graph,edge_weight_t>:: type WeightMap;

pair <int,int> solve(Graph& g){
  WeightMap wm=get(edge_weight,g);
  vector<Edge> mst;
  kruskal_minimum_spanning_tree(g,back_inserter(mst));
  vector<Edge>::iterator ebeg, eend=mst.end();

  int sum=0;
  for(ebeg=mst.begin();ebeg!=eend;ebeg++){
    sum+=wm[*ebeg];
  }

  int ver = num_vertices(g);
  vector<int> dist(ver);
  vector<int> pred(ver);

  dijkstra_shortest_paths(g,0,predecessor_map(make_iterator_property_map(pred.begin(),get(vertex_index,g))).
    distance_map(make_iterator_property_map(dist.begin(),get(vertex_index,g))));

  int maxval=0;
  int i;
  for(i=0;i<ver;i++){
    maxval=max(maxval,dist[i]);
  }
  return make_pair(sum,maxval);
}

int main(){
  ios_base::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    int n,m;
    cin>>n>>m;

    Graph g(n);
    WeightMap wm = get(edge_weight,g);
    int i;
    for(i=0;i<m;i++){
      int start,end,weight;
      cin>>start>>end>>weight;

      Edge e;
      tie(e,tuples::ignore)=add_edge(start,end,g);
      wm[e]=weight;
    }

    pair <int,int> sol=solve(g);
    cout<<sol.first<<" "<<sol.second<<endl;
  }
  return 0;
}