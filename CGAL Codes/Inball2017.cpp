#include <iostream>
#include <vector>
#include <cmath>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

using namespace CGAL;
using namespace std;

typedef Gmpzf ET;
typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

struct ineq{
	vector<int> vec;
	int b;
};

void solve(int n,int d, vector<ineq>& is){

	Program lp(SMALLER,false,0,false,0);

	int i,j;
	lp.set_l(d,true,0);
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			lp.set_a(j,i,is[i].vec[j]);
		}
		lp.set_r(i,SMALLER);
		lp.set_b(i,is[i].b);
	}

	int norm=0;
	for(i=0;i<n;i++){
		norm=0;
		for(j=0;j<d;j++){
			int a = is[i].vec[j];
			norm+=a*a;
		}
		norm=std::sqrt(norm);
		lp.set_a(d,i,norm);
	}

	lp.set_c(d,-1);

	Solution s = solve_quadratic_program(lp,ET());

	if(s.is_optimal()){
		double res = floor((-1)*to_double(s.objective_value()));
		if(res==-0)
			res=0;
		cout<<res<<endl;
	}else if(s.is_unbounded()){
		cout<<"inf"<<endl;
	}else if(s.is_infeasible()){
		cout<<"none"<<endl;
	}
}

int main(){
	while(true){
		int n,d;
		cin>>n;
		if(n==0)
			break;

		cin>>d;

		int i,j;
		vector<ineq> is(n);
		for(i=0;i<n;i++){
			for(j=0;j<d;j++){
				int a;
				cin>>a;
				is[i].vec.push_back(a);
			}
			cin>>is[i].b;
		}
		solve(n,d,is);
	}
}