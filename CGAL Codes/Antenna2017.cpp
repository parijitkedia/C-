#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Min_circle_2.h>
#include <CGAL/Min_circle_2_traits_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_exact_constructions_kernel_with_sqrt K;
typedef Min_circle_2_traits_2<K> Traits;
typedef Min_circle_2<Traits> Min_circle;
typedef K::Point_2 P;

long ceil_to_long(const K::FT& x){
	long a = ceil(to_double(x));
	while(a<x)
		a++;
	while(a-1>=x)
		a--;
	return a;
}

long solve(vector<P>& ans){
	Min_circle mc(ans.begin(),ans.end(),true);
	Traits::Circle c = mc.circle();

	K::FT radius = sqrt(c.squared_radius());
	return ceil_to_long(radius);
}	

int main(){

	ios_base::sync_with_stdio(false);
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;

		vector<P> ans;
		int i;
		for(i=0;i<n;i++){
			long x,y;
			cin>>x>>y;
			P p(x,y);
			ans.push_back(p);
		}

		long sol = solve(ans);
		cout<<sol<<endl;
	}
}