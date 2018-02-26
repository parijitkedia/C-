#include <iostream>
#include <vector>
#include <cmath>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> DTriang;
typedef K::Point_2 P;
typedef DTriang::Edge_iterator EdgeIt;

struct pos{
	int x;
	int y;
};

double ceil_to_double(const K::FT& x){
	double a = ceil(to_double(x));
	while(a<x) a++;
	while(a-1>=x) a--;
	return a;
}

void solve(int n, vector<pos>& gs){

	vector<P> ans;
	int i;
	for(i=0;i<n;i++){
		int x = gs[i].x;
		int y = gs[i].y;
		P p(x,y);
		ans.push_back(p);
	}

	DTriang t;
	t.insert(ans.begin(),ans.end());

	K::FT min_dist = t.segment(t.finite_edges_begin()).squared_length();
	for(EdgeIt e = t.finite_edges_begin();e!=t.finite_edges_end();e++){
		min_dist = std::min(min_dist,t.segment(e).squared_length());
	}
	min_dist=sqrt(min_dist*2500);
	cout<<ceil_to_double(min_dist)<<endl;
}

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;

		int i;
		vector<pos> gs(n);
		for(i=0;i<n;i++){
			cin>>gs[i].x;
			cin>>gs[i].y;
		}
		solve(n,gs);
	}
}