#include <iostream>
#include <cassert>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

using namespace std;

typedef CGAL::Gmpzf ET;

typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

int main(){
	
	double rho;
	cout<<"what is the expected return rate"<<endl;
	cin>>rho;

	Program qp(CGAL::LARGER,true,0,false,0);

	const int sw=-0;
	const int cs=1;

	qp.set_a(sw,0,.1); qp.set_a(cs,0,.51); qp.set_b(0,rho);

	qp.set_a(sw,1,1); qp.set_a(cs,1,1); qp.set_b(1,1); qp.set_r(1,CGAL::EQUAL);

	qp.set_d(sw,sw,.18);
	qp.set_d(cs,sw,-.1);
	qp.set_d(cs,cs,.5);

	Solution s = CGAL::solve_nonnegative_quadratic_program(qp,ET());
	assert(s.solves_quadratic_program(qp));

	if(s.status() == CGAL::QP_INFEASIBLE){

		cout<<"Expected return Rate "<<rho<<" not achieved"<<endl;
	}else{
		assert(s.status()==CGAL::QP_OPTIMAL);
		Solution::Variable_value_iterator opt = s.variable_values_begin();

		CGAL::Quotient<ET> sw_fraction = *opt;
		CGAL::Quotient<ET> cs_fraction = *(opt+1);

		cout<<"Minimum risk Investment "<<endl;
		cout<<100.0*CGAL::to_double(sw_fraction)<<"%"<<" in swatch"<<endl;
		cout<<100.0*CGAL::to_double(cs_fraction)<<"%"<<" in credit suisse"<<endl; 
	}
}