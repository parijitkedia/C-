#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;
typedef K::Ray_2 R;

bool solve(R ray, vector<S>& obs){
	for(auto o:obs){
		if(do_intersect(ray,o))
			return true;
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;

		long x,y,a,b;
		cin>>x>>y>>a>>b;
		P p(x,y), q(a,b);
		R r(p,q);

		int i;
		vector<S> obstacles;
		for(i=0;i<n;i++){
			long r,s,t,u;
			cin>>r>>s>>t>>u;
			P p(r,s),q(t,u);

			S seg(p,q);
			obstacles.push_back(seg);
		}

		bool ans = solve(r,obstacles);
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}