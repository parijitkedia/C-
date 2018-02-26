#include <iostream>
#include <vector>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

using namespace CGAL;
using namespace std;

typedef Gmpzf ET;
typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

struct nutrients{
	int minv;
	int maxv;
};

struct food{
	int price;
	vector<int> nuts;
};

void solve(int n,int m, vector<nutrients>& ns, vector<food>& fs){

	Program lp(SMALLER,true,0,false,0);

	int i,j;

	for(i=0;i<m;i++){
		lp.set_c(i,fs[i].price);
	}

	for(i=0;i<n;i++){

		lp.set_r(i,SMALLER);
		lp.set_b(i,ns[i].maxv);

		lp.set_r(m+i,LARGER);
		lp.set_b(m+i,ns[i].minv);

		for(j=0;j<m;j++){
			lp.set_a(j,i,fs[j].nuts[i]);
			lp.set_a(j,m+i,fs[j].nuts[i]);
		}
	}

	Solution s = solve_quadratic_program(lp,ET());
	if(!s.is_optimal() || s.is_unbounded())
		cout<<"No such diet."<<endl;
	else
		cout<<floor(to_double(s.objective_value()))<<endl;
}

int main(){
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;

		int i;
		vector<nutrients> ns(n);
		for(i=0;i<n;i++){
			cin>>ns[i].minv;
			cin>>ns[i].maxv;
		}

		int j;
		vector<food> fs(m);
		for(i=0;i<m;i++){
			cin>>fs[i].price;
			for(j=0;j<n;j++){
				int a;
				cin>>a;
				fs[i].nuts.push_back(a);
			}
		}

		solve(n,m,ns,fs);
	}
}