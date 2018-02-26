#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list_traits<vecS, vecS, directedS> 				Traits;
typedef adjacency_list<vecS, vecS, directedS, no_property,
property<edge_capacity_t, long,
property<edge_residual_capacity_t, long,
property<edge_reverse_t, Traits::edge_descriptor> > > > 			Graph;

typedef property_map<Graph, edge_capacity_t>::type 					EdgeCapacityMap;
typedef property_map<Graph, edge_residual_capacity_t>::type 		ResidualCapacityMap;
typedef property_map<Graph, edge_reverse_t>::type 					ReverseEdgeMap;
typedef graph_traits<Graph>::edge_descriptor						Edge;
typedef graph_traits<Graph>::out_edge_iterator 						OutEdgeIt;

struct EdgeAdder {
	EdgeAdder(Graph & G, EdgeCapacityMap &capacity, ReverseEdgeMap &rev_edge)
	: G(G), capacity(capacity), rev_edge(rev_edge) {}
	void addEdge(int u, int v, long c) {
		Edge e, reverseE;
		tie(e, tuples::ignore) = add_edge(u, v, G);
		tie(reverseE, tuples::ignore) = add_edge(v, u, G);
		capacity[e] = c;
		capacity[reverseE] = 0;
		rev_edge[e] = reverseE;
		rev_edge[reverseE] = e;
	}
	Graph &G;
	EdgeCapacityMap &capacity;
	ReverseEdgeMap  &rev_edge;
};

struct limb{
	int from;
	int to;
	int cost;
};

pair<int, vector<int> > solve(int n,int m, vector<limb>& limbs){
	Graph g(n);
	EdgeCapacityMap capacity = get(edge_capacity, g);
	ReverseEdgeMap rev_edge = get(edge_reverse, g);
	ResidualCapacityMap res_capacity = get(edge_residual_capacity, g);
	EdgeAdder ea(g,capacity, rev_edge);

	int i;
	for(i=0;i<m;i++){
		limb& l = limbs[i];
		ea.addEdge(l.from,l.to,l.cost);
	}

	int minflow=INT_MAX;
	int source,target;

	for(i=1;i<n;i++){
		int f1 = push_relabel_max_flow(g,0,i);
		if(f1<minflow){
			minflow=f1;
			source=0;
			target=i;
		}

		int f2 = push_relabel_max_flow(g,i,0);
		if(f2<minflow){
			minflow=f2;
			source=i;
			target=0;
		}
	}

	push_relabel_max_flow(g,source,target);

	queue<int> q;
	q.push(source);

	vector<bool> visited(n,false);

	while(!q.empty()){
		int from = q.front();
		q.pop();

		visited[from]=true;

		OutEdgeIt it,end;
		for(tie(it,end)=out_edges(from,g);it!=end;it++){
			int to=boost::target(*it,g);
			if(visited[to])
				continue;
			if(res_capacity[*it]==0)
				continue;
			q.push(to);
		}
	}

	vector<int> fs;
	for(i=0;i<n;i++){
		if(visited[i])
			fs.push_back(i);
	}
	return make_pair(minflow,fs);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		int i;
		vector<limb> ls(m);
		for(i=0;i<m;i++){
			cin>>ls[i].from;
			cin>>ls[i].to;
			cin>>ls[i].cost;
		}

		pair<int, vector<int> > sol = solve(n,m,ls);
		cout<<sol.first<<endl;

		vector<int> fs = sol.second;
		int a = fs.size();
		cout<<a;
		for(i=0;i<a;i++){
			cout<<" "<<fs[i];
		}
		cout<<endl;
	}
}