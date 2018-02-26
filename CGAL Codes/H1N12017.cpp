#include <iostream>
#include <queue>
#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_face_base_with_info_2.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Triangulation_vertex_base_2<K> Vb;
typedef Triangulation_face_base_with_info_2<bool,K> Fb;
typedef Triangulation_data_structure_2<Vb,Fb> Tds;
typedef Delaunay_triangulation_2<K,Tds>  Triangulation;

typedef Triangulation::Face_handle face_handle;
typedef Triangulation::Vertex_handle vertex_handle;
typedef Triangulation::All_faces_iterator  Face_iterator;

typedef K::Point_2 P;

char can_escape(Triangulation &t, P &u, double d){
	face_handle f = t.locate(u); //t.inexact_locate(u);
	
	if(to_double(squared_distance(u, t.nearest_vertex(u)->point())) < d)  
		return 'n';
	
	for (Face_iterator f1 = t.all_faces_begin(); f1 != t.all_faces_end(); ++f1){
		f1->info() = false;
	}
	
	queue<face_handle> q;
	f->info() = false;
	q.push(f);

	while(!q.empty()){
		face_handle f_front = q.front();
		q.pop();
		if(t.is_infinite(f_front)){
			return 'y';
		}
		
		f_front->info() = true;
		
		for(int i=0; i<3; i++){
			face_handle cur = f_front->neighbor(i);
			if(cur->info()) continue;
			
			vertex_handle v1 = f_front->vertex((i+1)%3);
			vertex_handle v2 = f_front->vertex((i+2)%3);	
			
			if(t.is_infinite(v1) || t.is_infinite(v2)) continue;

			if(to_double(squared_distance(v1->point(), v2->point())) >= 4*d){
				q.push(cur);
			}
		}
	}
	return 'n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==0)
			break;

		vector<P> points;

		for(int i=0; i<n; i++){
			int x, y;
			cin>>x>>y;
			P point(x, y);
			points.push_back(point);
		}

		Triangulation t;
		t.insert(points.begin(), points.end());

		int m;
		cin>>m;

		for(int i=0; i<m; i++){
			int x, y;
			double d;
			cin>>x>>y>>d;
			P user(x, y);
			cout<<can_escape(t, user, d);
		}
		cout<<endl;
	}
}