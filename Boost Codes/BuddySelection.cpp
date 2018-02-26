#include <iostream>
#include <vector>
#include <map>
#include <set>

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS,vecS,undirectedS> Graph;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef property_map<Graph, edge_weight_t>::type WeightMap;

bool solve(int nrstud, vector<set<int> > students, int nrchar, int minchar){
	Graph g(nrstud);
	int i,j;
	for(i=0;i<nrstud;i++){
		for(j=i+1;j<nrstud;j++){
			Edge edge;
			bool success;
			vector<int> intersection(nrchar);
			auto it=set_intersection(students[i].begin(),students[i].end(),
						students[j].begin(),students[j].end(),intersection.begin());
			int size = it-intersection.begin();
			if(size<=minchar)
				continue;
			tie(edge,success)=add_edge(i,j,g);
		}
	}
	vector<Vertex> mate(nrstud);
	checked_edmonds_maximum_cardinality_matching(g,&mate[0]);
	int s=matching_size(g,&mate[0]);
	return s<(nrstud/2);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c,f;
		cin>>n>>c>>f;

		vector<set<int> >students(n);
		int wordcount=0;
		map<string,int> strmap;
		int i,j;
		for(i=0;i<n;i++){
			set<int> student;
			for(j=0;j<c;j++){
				string s;
				cin>>s;

				if(strmap.find(s) == strmap.end()){
					strmap.insert(make_pair(s,wordcount));
					wordcount++;
				}
				student.insert(strmap[s]);
			}
			students[i]=student;
		}
		if(solve(n,students,c,f))
			cout<<"optimal"<<endl;
		else
			cout<<"not optimal"<<endl;
	}
}