#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> DTriang;
typedef K::Point_2 P;

struct rest{
	int x;
	int y;
};

vector<double> solve(int n,int m, vector<rest>& ors, vector<rest>& nrs){

	vector<P> ans;
	int i;
	for(i=0;i<n;i++){
		int x = ors[i].x;
		int y = ors[i].y;
		P p(x,y);
		ans.push_back(p);
	}

	DTriang t;
	t.insert(ans.begin(),ans.end());

	vector<double> res;
	for(i=0;i<m;i++){
		int x = nrs[i].x;
		int y = nrs[i].y;

		P p(x,y);

		P nearest = t.nearest_vertex(p)->point();
		res.push_back(to_double(squared_distance(nearest,p)));
	}
	return res;
}

int main(){
	cout<<fixed<<setprecision(0);
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;

		vector<rest> ors(n);
		int i;
		for(i=0;i<n;i++){
			cin>>ors[i].x;
			cin>>ors[i].y;
		}

		int m;
		cin>>m;
		vector<rest> nrs(m);
		for(i=0;i<m;i++){
			cin>>nrs[i].x;
			cin>>nrs[i].y;
		}

		vector<double> sol = solve(n,m,ors,nrs);
		for(i=0;i<m;i++){
			cout<<sol[i]<<endl;
		}
	}
}