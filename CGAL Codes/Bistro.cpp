#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> DTriang;
typedef DTriang::Edge_iterator EdgeIt;
typedef DTriang::Vertex_handle VertexH;
typedef K::Point_2 P;
typedef K::FT F;

struct rest{
	int x;
	int y;
};

vector<double> solve(int n, int m, vector<rest>& old, vector<rest>& nwr){
	vector<P> ps;
	int i;
	for(i=0;i<n;i++){
		int x=old[i].x;
		int y=old[i].y;
		P r(x,y);
		ps.push_back(r);
	}
	DTriang t;
	t.insert(ps.begin(),ps.end());

	vector<double> res;
	for(i=0;i<m;i++){
		int x=nwr[i].x;
		int y=nwr[i].y;
		P s(x,y);

		P nearest = t.nearest_vertex(s)->point();
		res.push_back(to_double(squared_distance(s,nearest)));
	}
	return res;
}

int main(){
	cout<<fixed<<setprecision(0);
	while(true){
		int n,m;
		cin>>n;
		int i,x,y;

		if(n==0)
			break;

		vector<rest> ors(n);
		for(i=0;i<n;i++){
			cin>>ors[i].x;
			cin>>ors[i].y;
		}

		cin>>m;
		vector<rest> nrs(m);
		for(i=0;i<m;i++){
			cin>>nrs[i].x;
			cin>>nrs[i].y;
		}

		vector<double> sol = solve(n,m,ors,nrs);
		for(i=0;i<m;i++)
			cout<<sol[i]<<endl;
	}
}