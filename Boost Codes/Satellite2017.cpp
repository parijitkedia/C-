#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS> Graph;
typedef graph_traits<Graph>::edge_descriptor    Edge;
typedef graph_traits<Graph>::vertex_descriptor  Vertex;
typedef graph_traits<Graph>::out_edge_iterator  OutEdgeIt;

struct lnk{
	int station;
	int satellite;
};

pair<vector<int>, vector<int> > solve(int g,int s,int l, vector<lnk>& links){

	Graph graph(g+s);
	int i;
	for(i=0;i<l;i++){
		lnk& l = links[i];
		Vertex from = l.station;
		Vertex to = l.satellite+g;
		Edge e;
		bool success;
		tie(e,success)=add_edge(from,to,graph);
	}
	
	vector<Vertex> mate(g+s);
	checked_edmonds_maximum_cardinality_matching(graph,&mate[0]);

	stack<int> q;
	vector<bool> visited(g+s,false);

	for(i=0;i<g;i++){
		if(mate[i]==graph_traits<Graph>::null_vertex()){
			q.push(i);
		}
	}

	while(!q.empty()){
		int from = q.top();
		q.pop();

		visited[from]=true;
		OutEdgeIt ebeg,eend;
		for(tie(ebeg,eend)=out_edges(from,graph);ebeg!=eend;ebeg++){
			int to = boost::target(*ebeg,graph);
			if(visited[to])
				continue;

			int m = mate[from];

			bool follow = (from<to && m!=to) || (to<from && m==to);

			if(follow)
				q.push(to);
		}
	}	

	vector<int> stations;
	vector<int> satellites;

	for(i=0;i<g;i++){
		if(visited[i])
			continue;
		stations.push_back(i);
	}

	for(i=g;i<g+s;i++){
		if(!visited[i])
			continue;
		satellites.push_back(i-g);
	}

	return make_pair(stations,satellites);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int g,s,l;
		cin>>g>>s>>l;

		vector<lnk> ls(l);
		int i;
		for(i=0;i<l;i++){
			cin>>ls[i].station;
			cin>>ls[i].satellite;
		}

		pair<vector<int>,vector<int> > sol = solve(g,s,l,ls);
		vector<int>& sts = sol.first;
		vector<int>& sas = sol.second;
		int n = sts.size();
		int m = sas.size();
		cout<<n<<" "<<m<<endl;
		for(i=0;i<n;i++){
			cout<<sts[i]<<" ";
		} 
		for(i=0;i<m;i++){
			cout<<sas[i]<<" ";
		}
		cout<<endl;
	}
}