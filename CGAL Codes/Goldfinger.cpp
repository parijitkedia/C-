#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <CGAL/Gmpq.h>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Gmpq ET;
typedef Quadratic_program<ET> Program;
typedef Quadratic_program_solution<ET> Solution;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;

typedef Delaunay_triangulation_2<K>  Triangulation;

bool feasible(vector<P>& mpe, vector<K::FT>& mperad, vector<pair<P,int> >& sensor, int I, int mid){
	Program lp(LARGER,true,0,false,0);

	int i,j;
	for(i=0;i<sensor.size();i++){
		P p=sensor[i].first;
		lp.set_b(i,sensor[i].second);
		for(j=0;j<mid;j++){
			K::FT dist = squared_distance(mpe[j],p);
			if(mperad[j]==-1 || dist<=mperad[j]){
				lp.set_a(j,i,ET(1)/dist);
			}
		}
	}
	lp.set_b(sensor.size(),I);
	lp.set_r(sensor.size(),SMALLER);
	for(i=0;i<mid;i++){
		lp.set_a(i,sensor.size(),1);
	}

	Solution s = solve_nonnegative_linear_program(lp,ET());
	if(s.status()==QP_OPTIMAL)
		return true;
	else
		return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n,m,h,I;
		cin>>n>>m>>h>>I;

		vector<pair<P,int> > sensor(n);
		int i;
		for(i=0;i<n;i++){
			int x,y,r;
			cin>>x>>y>>r;
			sensor[i]=make_pair(P(x,y),r);
		}

		vector<P> mpe(m);
		for(i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			mpe[i]=P(x,y);
		}

		vector<P> hench(h);
		for(i=0;i<h;i++){
			int x,y;
			cin>>x>>y;
			hench[i]=P(x,y);
		}

		vector<K::FT> mperad(m,-1);
		if(h>0){
			Triangulation t;
			t.insert(hench.begin(),hench.end());

			for(i=0;i<m;i++){
				P nearest = t.nearest_vertex(mpe[i])->point();
				mperad[i]=squared_distance(mpe[i],nearest);
			}
		}

		int low=1,high=m;

		while(low*2 < high && !feasible(mpe,mperad,sensor,I,low*2)){
			low*=2;
		}

		if(low*2 < high){
			high=low*2;
		}

		while(low<=high){
			int mid = low+(high-low)/2;
			if(feasible(mpe,mperad,sensor,I,mid)){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}
		if(low>m)
			cout<<"impossible"<<endl;
		else
			cout<<low<<endl;
	}
}
