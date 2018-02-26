#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>

using namespace std;
using namespace CGAL;

typedef Gmpz ET;

typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

int main(){

	Program lp(SMALLER,false,0,false,0);

	const int alpha = 0;
	const int beta = 1;
	const int gamma = 2;
	const int delta = 3;

	int m,n;
	cin>>m>>n;
	int i,j;
	//red points
	for(i=0;i<m;i++){
		int x,y;
		cin>>x>>y;

		lp.set_a(alpha,i,-x);
		lp.set_a(beta,i,-y);
		lp.set_a(gamma,i,-1);
		lp.set_b( i,-x*x - y*y);
	}
	//blue points
	for(j=0;j<n;j++){
		int x,y;
		cin>>x>>y;

		lp.set_a(alpha,m+j,x);
		lp.set_a(beta,m+j,y);
		lp.set_a(gamma,m+j,1);
		lp.set_a(delta,m+j,1);
		lp.set_b( m+j,x*x + y*y);
	}

	lp.set_c(delta,-1);

	lp.set_u(delta,true,1);

	Solution s = CGAL::solve_linear_program(lp,ET());
	assert(s.solves_linear_program(lp));

	if(s.is_optimal() && s.objective_value()<0){ 

		Quadratic_program_solution<ET>::Variable_value_iterator opt = s.variable_values_begin();

		Quotient<ET> alpha = *opt;
		Quotient<ET> beta = *(opt+1);
		Quotient<ET> gamma = *(opt+2);
		cout<<"Valid Exposure"<<endl;
		cout<<"Center "<<alpha/2<<" "<<beta/2<<endl;
		cout<<"Radius "<<gamma+alpha*alpha/4+beta*beta/4<<endl;
	}else{
		cout<<"No Valid Exposure"<<endl;
	}
}