#include <iostream>
#include <vector>

#include <CGAL/basic.h>
#include <CGAL/QP_functions.h>
#include <CGAL/QP_models.h>

using namespace std;
using namespace CGAL;

#include <CGAL/Gmpz.h>

typedef Gmpz ET;

typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

struct asset{
	int cost;
	int ret;
};

struct investor{
	int maxcost;
	int minret;
	int maxvar; 
};

vector<bool> solve(int n, int m, vector<asset>& assets, vector<vector<int> >& var, vector<investor>& investors){
	vector<bool> result(m,false);

	Program p(SMALLER,true,0,false,0);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			p.set_d(i,j,2*var[i][j]);
		}
	}

	for(i=0;i<n;i++){
		p.set_a(i,0,assets[i].cost);
		p.set_a(i,1,assets[i].ret);
	}
	p.set_r(0,SMALLER);
	p.set_r(1,LARGER);

	for(i=0;i<m;i++){
		p.set_b(0,investors[i].maxcost);
		p.set_b(1,investors[i].minret);

		Solution s = solve_quadratic_program(p,ET());

		if(s.is_optimal() && s.objective_value() <= investors[i].maxvar)
			result[i]=true;
	}
	return result;
}

int main(){
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;

		vector<asset> as(n);
		int i,j;
		for(i=0;i<n;i++){
			cin>>as[i].cost;
			cin>>as[i].ret;
		}

		vector<vector<int> > vars(n,vector<int>(n));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>vars[i][j];
			}
		}

		vector<investor> is(m);
		for(i=0;i<m;i++){
			cin>>is[i].maxcost;
			cin>>is[i].minret;
			cin>>is[i].maxvar;
		}

		vector<bool> solution = solve(n,m,as,vars,is);
		for(i=0;i<m;i++){
			if(solution[i])
				cout<<"Yes."<<endl;
			else
				cout<<"No."<<endl;
		}
	}
}