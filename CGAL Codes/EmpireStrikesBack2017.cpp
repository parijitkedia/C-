#include <iostream>
#include <vector>
#include <cmath>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Triangulation;

typedef CGAL::Gmpq ET;
typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

typedef K::Point_2 P;
typedef K::FT F;

struct asteroids{
	int x;
	int y;
	int d;
};

struct shooting{
	int x;
	int y;
};

struct bounty{
	int x;
	int y;
};

bool solve(int a,int s,int b,int e, vector<asteroids>& as, vector<shooting>& sh, vector<bounty>& bt){
	
	Program lp(LARGER,true,0,false,0);
	int i,j;
	vector<P> asts;
	for(i=0;i<a;i++){
		int x=as[i].x;
		int y=as[i].y;
		P p(x,y);
		lp.set_b(i,as[i].d);
		asts.push_back(p);
	}

	vector<P> shs;
	for(i=0;i<s;i++){
		int x = sh[i].x;
		int y = sh[i].y;
		P p(x,y);
		lp.set_c(i,1);
		shs.push_back(p);
	}

	vector<P> bts;
	for(i=0;i<b;i++){
		int x = bt[i].x;
		int y = bt[i].y;
		P p(x,y);
		bts.push_back(p);
	}

	Triangulation t;

	/*vector<F> dist;
	if(b>0){
		t.insert(bts.begin(),bts.end());
		for(i=0;i<s;i++){
			auto nearest = t.nearest_vertex(shs[i])->point();
			dist.push_back(squared_distance(shs[i],nearest));
		}
	}

	for(i=0;i<a;i++){
		for(j=0;j<s;j++){
			F sqdist = squared_distance(shs[j],asts[i]);
			if(sqdist<dist[j]){
				if(sqdist>0){
					lp.set_a(j,i,1/ET(sqdist));
				}else{
					lp.set_a(j,i,1);
				}
			}
		}
	}*/
	t.insert(bts.begin(),bts.end());
	for(i=0;i<s;i++){
		ET r2 = -1;
		if(b>0){
			auto nearest = t.nearest_vertex(shs[i])->point();
			r2 = squared_distance(shs[i],nearest);
		}

		for(j=0;j<a;j++){
			ET dist = squared_distance(shs[i],asts[j]);
			if(r2 == -1 || dist<=r2)
				lp.set_a(i,j,ET(1)/max(ET(1),dist));
		}
	}

	Solution sol = solve_linear_program(lp,ET());
	if(sol.is_infeasible() || sol.objective_value()>e)
		return false;
	else
		return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int a,s,b;
		cin>>a>>s>>b;
		
		int e;
		cin>>e;

		vector<asteroids> as(a);
		int i;
		for(i=0;i<a;i++){
			cin>>as[i].x;
			cin>>as[i].y;
			cin>>as[i].d;
		}

		vector<shooting> sh(s);
		for(i=0;i<s;i++){
			cin>>sh[i].x;
			cin>>sh[i].y;
		}

		vector<bounty> bt(b);
		for(i=0;i<b;i++){
			cin>>bt[i].x;
			cin>>bt[i].y;
		}
		if(solve(a,s,b,e,as,sh,bt))
			cout<<"y"<<endl;
		else
			cout<<"n"<<endl;
	}
}