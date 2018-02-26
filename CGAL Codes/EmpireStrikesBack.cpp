#include <iostream>
#include <vector>

#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> DTriang;
typedef DTriang::Edge_iterator EdgeIt;
typedef DTriang::Vertex_handle VertexH;
typedef K::Point_2 P;
typedef K::FT F;

typedef Gmpzf ET;

typedef Quadratic_program<double> Program;
typedef Quadratic_program_solution<ET> Solution;

struct asteroids{
	long long int x;
	long long int y;
	int d;
};

struct shooting{
	long long int x;
	long long int y;
};

struct bounty{
	long long int x;
	long long int y;
};

void solve(int e, vector<asteroids>& ass, vector<shooting>& shs, vector<bounty>& bts){
	int i,j;
	vector<P> asts;
	for(i=0;i<ass.size();i++){
		int x=ass[i].x;
		int y=ass[i].y;
		P p(x,y);
		asts.push_back(p);
	}

	vector<P> btys;
	for(i=0;i<bts.size();i++){
		int x=bts[i].x;
		int y=bts[i].y;
		P p(x,y);
		btys.push_back(p);
	}

	DTriang t;
	t.insert(btys.begin(),btys.end());
	Program lp(LARGER,true,0,false,0);

	vector<P> shos;
	for(i=0;i<shs.size();i++){
		int x=shs[i].x;
		int y=shs[i].y;
		P p(x,y);
		if(btys.size()>0){
			P nearest = t.nearest_vertex(p)->point();
			shos.push_back(squared_distance(p,nearest));
		}	
		lp.set_c(i,1);
	}

	for(i=0;i<shos.size();i++){
		for(j=0;j<btys.size();j++){
			F sqdist = squared_distance(asts[i],shos[j]);
			if(sqdist<shos[j]){
				if(sqdist>0){
					lp.set_a(j,i,1/ET(sqdist));
				}else{
					lp.set_a(j,i,1);
				}
			}
		}
		lp.set_b(i,ass[i].d);
	}

	Solution sol = solve_linear_program(lp,ET());
	if(sol.is_infeasible() || sol.objective_value()>e)
		cout<<"n"<<endl;
	else
		cout<<"y"<<endl; 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,s,b;
		cin>>a>>s>>b;
		int e;
		cin>>e;

		int i;
		vector<asteroids> as;
		for(i=0;i<a;i++){
			cin>>as[i].x;
			cin>>as[i].y;
			cin>>as[i].d;
		}

		vector<shooting> sh;
		for(i=0;i<s;i++){
			cin>>sh[i].x;
			cin>>sh[i].y;
		}

		vector<bounty> bt;
		for(i=0;i<b;i++){
			cin>>bt[i].x;
			cin>>bt[i].y;
		}

		solve(e,as,sh,bt);
	} 
}