#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace CGAL;

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Segment_2 S;
typedef K::Ray_2 R;
typedef K::Point_2 P;

bool solve_sol(R ray, vector<S>& obs){
	for(auto o:obs){
		bool intersect = do_intersect(ray,o);
		if(intersect)
			return true;
	}
	return false;
}

int main(){

	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;
		int i;

		long x,y,a,b;
		cin>>x>>y>>a>>b;
		P p(x,y), q(a,b);
		R ray(p,q);

		vector<S> obs;

		for(i=0;i<n;i++){
			long x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			P p1(x1,y1), q1(x2,y2);
			S s(p1,q1);
			obs.push_back(s);
		}

		if(solve_sol(ray,obs))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}