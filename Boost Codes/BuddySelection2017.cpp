#include <iostream>
#include <vector>
#include <set>
#include <map>

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,undirectedS> Graph;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::vertex_descriptor Vertex;

bool solve(int n,int c,int f, vector<set<int> >& students){
	Graph G(n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			Edge e;

			vector<int> intersection(c);
			auto it = set_intersection(students[i].begin(),students[i].end(),students[j].begin(),students[j].end(),intersection.begin());
			int size = it - intersection.begin();
			if(size<=f)
				continue;
			tie(e,tuples::ignore)=add_edge(i,j,G);
		}
	}

	vector<Vertex> mate(n);
	checked_edmonds_cardinality_matching(G,&mate[0]);
	int s = matching_size(G,&mate[0]);
	return s<n/2;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c,f;
		cin>>n>>c>>f;

		vector<set<int> >students(n);
		map<string,int> strmap;

		int i,j;
		int wc=0;
		for(i=0;i<n;i++){
			set<int> student;
			for(j=0;j<c;j++){
				string str;
				cin>>str;

				if(strmap.find(str)==strmap.end()){
					strmap.insert(make_pair(str,wc));
					wc++;
				}
				student.insert(strmap[str]);
			}
			students[i]=student;
		}
		bool ans = solve(n,c,f,students);
		if(ans)
			cout<<"optimal"<<endl;
		else
			cout<<"not optimal"<<endl;
	}
}