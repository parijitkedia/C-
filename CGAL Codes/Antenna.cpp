#include <iostream>
#include <vector>
#include <cmath>

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

long solve_sol(vector<P> home){
	Min_circle mc (home.begin(),home.end(),true);
	
	K::FT radius = sqrt(mc.circle().squared_radius());
	return ceil_to_long(radius);
}

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;

		vector<P> home;
		int i;
		for(i=0;i<n;i++){
			long x,y;
			cin>>x>>y;
			P p(x,y);
			home.push_back(p);
		}
		cout<<solve_sol(home)<<endl;
	}
}