#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpzf.h>

using namespace std;
using namespace CGAL;

typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<double> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

bool degree(vector<tuple<long int,long int,long int> >& arr, int h, int mid){

	Program lp(LARGER,false,0,false,0);

	for(int i=0;i<arr.size();i++){
		int id=0;
		tuple<long int,long int,long int>& cell=arr[i];
		for(int x=0;x<=mid;x++){
			for(int y=0;y<=mid;y++){
				for(int z=0;z<=mid;z++){
					if(x+y+z<=mid){
						lp.set_a(id,i,pow(get<0>(cell),x)*pow(get<1>(cell),y)*pow(get<2>(cell),z));
						id++;
					}else{
						break;
					}
				}
			}
		}
		if(i<h){
			lp.set_b(i,1);
			lp.set_r(i,LARGER);
		}else{
			lp.set_b(i,-1);
			lp.set_r(i,SMALLER);
		}
	}

	Quadratic_program_options options;
	options.set_pricing_strategy(QP_BLAND);
	Solution s = solve_quadratic_program(lp,ET(),options);
	return !s.is_infeasible();
}

int find(int minv,int maxv,vector<tuple<long int,long int,long int> >& arr, int h){
	int sol=-1;
	int i;
	for(i=minv;i<=maxv;i+=3){
		if(degree(arr,h,i)){
			sol=i;
			break;
		}
	}
	if(sol!=0){
		if(degree(arr,h,sol-2)){
			sol=sol-2;
		}else if(degree(arr,h,sol-1)){
			sol=sol-1;
		}
	}
	return sol;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	cout<<fixed<<setprecision(0);
	while(t--){
		int h,t;
		cin>>h>>t;

		int total = h+t;
		vector<tuple<long int,long int,long int> > arr;
		int i;
		for(i=0;i<total;i++){
			long int a,b,c;
			cin>>a>>b>>c;
			arr.push_back(make_tuple(a,b,c));
		}

		int sol = find(0,30,arr,h);
		if(sol==-1)
			cout<<"Impossible!"<<endl;
		else
			cout<<sol<<endl;
	}
}