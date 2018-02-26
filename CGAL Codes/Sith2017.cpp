#include <iostream>
#include <map>
#include <vector>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>

using namespace std;
using namespace CGAL;
using namespace boost;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> Triangulation;
typedef K::Point_2 P;

typedef adjacency_list<vecS,vecS,undirectedS> Graph;

bool check(vector<P>& planet, map<P,int>& vid, int mid, double r ){

	Graph G;
	Triangulation t;
	t.insert(planet.begin()+mid,planet.end());
	
	for(auto it = t.finite_edges_begin(); it!=t.finite_edges_end(); it++){
		auto p1 = it->first->vertex((it->second+1)%3)->point();
		auto p2 = it->first->vertex((it->second+2)%3)->point();
		if(squared_distance(p1,p2)<=r){
			add_edge(vid[p1],vid[p2],G);
		}
	}

	if(num_vertices(G)==0)
		return false;
	vector<int> component(num_vertices(G));
	int ncomp = connected_components(G,&component[0]);
	vector<int> ele(ncomp,0);
	int i;
	for(i=0;i<component.size();i++){
		ele[component[i]]++;
	}
	return *max_element(ele.begin(),ele.end())>=mid;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		double r;
		cin>>n>>r;

		double dist = r*r;
		
		vector<P> planet;
		map<P,int> vid;

		int i;
		for(i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			P p(x,y);
			planet.push_back(p);
			vid.insert(make_pair(p,i));
		}

		int high=n/2;
		int low=1;
		int k=1;
		while(low<=high){
			int mid = low + (high-low)/2;
			if(check(planet,vid,mid,dist)){
				k=mid;
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
		cout<<k<<endl;
	}
}