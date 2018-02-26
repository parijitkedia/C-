#include <iostream>
#include <vector>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>

using namespace std;
using namespace CGAL;

#ifdef CGAL_USE_GMP
#include <CGAL/Gmpz.h>
typedef Gmpz ET;
#else
#include <CGAL/MP_Float.h>
typedef MP_Float ET;
#endif


typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

struct nut{
	int minv;
	int maxv;
};

struct food{
	int price;
	vector<int> nuts;
};

double solve(int n, int m, vector<nut>& nuts, vector<food>& foods){

	Program p(SMALLER,true,0,false,0);
	int i,j;

	for(j=0;j<m;j++){
		p.set_c(j,foods[j].price);
	}

	for(i=0;i<n;i++){
		p.set_r(i,SMALLER);
		p.set_b(i,nuts[i].maxv);

		p.set_r(m+i,LARGER);
		p.set_b(m+i,nuts[i].minv);

		for(j=0;j<m;j++){
			p.set_a(j,i,foods[j].nuts[i]);
			p.set_a(j,m+i,foods[j].nuts[i]);
		}
	}
	Solution s = solve_quadratic_program(p,ET());
	assert(s.solves_quadratic_program(p));

	if(!s.is_optimal() || s.is_unbounded())
		return 0;
	else
		return floor(to_double(s.objective_value()));
}

int main(){
	cout<<setprecision(15);
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;

		vector<nut> ns(n);
		int i,j;
		for(i=0;i<n;i++){
			cin>>ns[i].minv;
			cin>>ns[i].maxv;
		}

		vector<food> fs(m);
		for(i=0;i<m;i++){
			cin>>fs[i].price;
			for(j=0;j<n;j++){
				int c;
				cin>>c;
				fs[i].nuts.push_back(c);
			}
		}

		double result = solve(n,m,ns,fs);
		if(result>0)
			cout<<result<<endl;
		else
			cout<<"No such diet."<<endl;
	}
}
