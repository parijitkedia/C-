#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Min_circle_2.h>
#include <CGAL/Min_circle_2_traits_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_exact_constructions_kernel_with_sqrt K;
typedef Min_circle_2_traits_2<K> Traits;
typedef Min_circle_2<Traits> 	Min_circle;
typedef K::Point_2 P;

double ceil_to_double(const K::FT& x){
	double a = ceil(to_double(x));
	while(a<x)
		a++;
	while(a-1>=x)
		a--;
	return a;
}

long solve(vector<P>& ans){
	Min_circle mc(ans.begin(),ans.end(),true);
	Traits::Circle c = mc.circle();

	K::FT min_radius = numeric_limits<double>::max();

	for(auto i = mc.support_points_begin();i<mc.support_points_end();i++){
		vector<P> copy(ans);
		for(auto j = copy.begin();j<copy.end();j++){
			if(*i==*j)
				copy.erase(j);
		}

		Min_circle c(copy.begin(),copy.end(),true);
		if(c.circle().squared_radius()<min_radius)
			min_radius = c.circle().squared_radius();
	}

	return ceil_to_double(sqrt(min_radius));
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

		cout<<solve(ans)<<endl;
	}
}