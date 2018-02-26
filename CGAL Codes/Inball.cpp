#include <iostream>
#include <vector>
#include <cmath>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>

using namespace std;
using namespace CGAL;

#include <CGAL/Gmpz.h>
typedef Gmpz ET;

typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

struct ineq{
	vector<int> vec;
	int b;
};

void solve(int n, int d, vector<ineq>& ineqs){

/*	Program p(SMALLER,false,0,false,0);

	p.set_l(d,true,0);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			p.set_a(j,i,ineqs[i].vec[j]);
		}
		p.set_r(i,SMALLER);
		p.set_b(i,ineqs[i].b);
	}

	for(i=0;i<n;i++){
		int norm=0;
		for(j=0;j<d;j++){
			int a= ineqs[i].vec[j];
			norm+=a*a;
		}
		norm=sqrt(norm);
		p.set_a(d,i,norm);
	}
	p.set_c(d,-1);

	Solution s = solve_linear_program(p,ET());
	if(s.is_optimal()){
		double res=floor(-to_double(s.objective_value()));
		if(res==-0)
			res=0;
		cout<<res<<endl;
	}
	else if(s.is_infeasible())
		cout<<"none"<<endl;
	else if(s.is_unbounded())
		cout<<"inf"<<endl; */
}

int main(){
	ios_base::sync_with_stdio(false);
	/*cout<<setprecision(15);
	while(true){
		int n,d;
		cin>>n>>d;
		if(n==0)
			break;
		vector<ineq> is(n);
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<d;j++){
				int a;
				cin>>a;
				is[i].vec.push_back(a);
			}
			cin>>is[i].b;
		}
		solve(n,d,is);
	} */
}
