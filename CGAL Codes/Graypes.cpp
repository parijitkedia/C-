#include <iostream>
#include <vector>
#include <cmath>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> DTriang;
typedef DTriang::Edge_iterator EdgeIt;
typedef K::Point_2 P;
typedef K::FT F;

struct pos{
	int x;
	int y;
};

double ceil_to_double(const F& x){
	double a = ceil(to_double(x));
	while(a<x)
		a++;
	while(a-1>=x)
		a--;
	return a;
}

double solve(int n, vector<pos>& graypes){
	vector<P> ps;
	int i;
	for(i=0;i<n;i++){
		int x=graypes[i].x;
		int y=graypes[i].y;
		P p(x,y);
		ps.push_back(p);
	}

	DTriang t;
	t.insert(ps.begin(),ps.end());

	F mindist = t.segment(t.finite_edges_begin()).squared_length();
	for(EdgeIt e=t.finite_edges_begin(); e!=t.finite_edges_end();e++){
		mindist = min(mindist,t.segment(e).squared_length());
	}
	mindist=sqrt(mindist*100*100/(2*2));
	return ceil_to_double(mindist); 
} 

int main(){
	ios_base::sync_with_stdio(false);
	cout<<setprecision(15);
	while(true){
		int n;
		cin>>n;
		int i;
		if(n==0)
			break;

		vector<pos> gs(n);
		for(i=0;i<n;i++){
			cin>>gs[i].x;
			cin>>gs[i].y;
		}
		double solution = solve(n,gs);
		cout<<solution<<endl;
	}	
}	