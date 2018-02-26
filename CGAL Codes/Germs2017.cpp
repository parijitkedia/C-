#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;

typedef CGAL::Triangulation_vertex_base_with_info_2<double, K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds>  Triangulation;

typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Finite_vertices_iterator Vertex_iterator;
typedef Triangulation::Vertex_handle VertexH;

typedef K::Point_2 P;
typedef K::Segment_2 S;

double ceil_to_double(K::FT const& x){
	double a = ceil(to_double(x));
	while(a<x) a+=1;
	while(a-1>=x) a-=1;
	return a;
}

double time_dist(double x){
	return ceil_to_double( sqrt( ( sqrt(x) - 1)/2.0 ) );
}

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;

		int l,b,r,t;
		cin>>l>>b>>r>>t;

		vector<P> points;
		int i;
		for(i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			P p(x,y);
			points.push_back(p);
		}

		Triangulation Dtriang;
		Dtriang.insert(points.begin(),points.end());

		for(Vertex_iterator v = Dtriang.finite_vertices_begin(); v!=Dtriang.finite_vertices_end(); v++){
			P p = v->point();
			double horiz = std::min(p.x()-l,r-p.x());
			double vert = std::min(p.y()-b, t-p.y());
			double over = std::min(horiz,vert);
			v->info() = 4*over*over;
		}

		for(Edge_iterator e = Dtriang.finite_edges_begin(); e!=Dtriang.finite_edges_end(); e++){
			VertexH v1 = e->first->vertex((e->second+1)%3);
			VertexH v2 = e->first->vertex((e->second+2)%3);
			double dist = to_double(Dtriang.segment(e).squared_length());
			if(dist < v1->info())
				v1->info() = dist;
			if(dist < v2->info())
				v2->info() = dist;
		}

		vector<double> destroy;
		for(Vertex_iterator v = Dtriang.finite_vertices_begin(); v!=Dtriang.finite_vertices_end(); v++){
			destroy.push_back(v->info());
		}

		sort(destroy.begin(),destroy.end());

		cout<<setiosflags(ios::fixed)<<setprecision(0);
		cout<<time_dist(destroy[0])<<" ";
		cout<<time_dist(destroy[n/2])<<" ";
		cout<<time_dist(destroy[n-1])<<endl;
	}
}