#include <iostream>
#include <vector>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>

using namespace CGAL;
using namespace std;

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

vector<bool> solve(int n,int m, vector<asset>& as, vector<vector<int> >& vars, vector<investor>& is){

	vector<bool> ans(m,false);
	Program lp(SMALLER,true,0,false,0);

	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			lp.set_d(i,j,2*vars[i][j]);
		}
	}

	for(i=0;i<n;i++){
		lp.set_a(i,0,as[i].cost);
		lp.set_a(i,1,as[i].ret);
	}

	lp.set_r(0,SMALLER);
	lp.set_r(1,LARGER);

	for(i=0;i<m;i++){

		lp.set_b(0,is[i].maxcost);
		lp.set_b(1,is[i].minret);

		Solution s = solve_quadratic_program(lp,ET());

		if(s.is_optimal() && s.objective_value()<=is[i].maxvar)
			ans[i]=true;
	}
	return ans;
}

int main(){
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;

		int i,j;
		vector<asset> as(n);
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

		vector<bool> sol = solve(n,m,as,vars,is);
		for(i=0;i<m;i++){
			if(sol[i])
				cout<<"Yes."<<endl;
			else
				cout<<"No."<<endl;
		}
	}
}