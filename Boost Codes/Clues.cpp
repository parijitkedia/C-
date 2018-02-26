#include <iostream>
#include <vector>
#include <map>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/bipartite.hpp>

using namespace std;
using namespace CGAL;
using namespace boost;

typedef adjacency_list<vecS,vecS,undirectedS, no_property, no_property> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;
typedef	graph_traits<Graph>::edge_iterator EdgeIt;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> Triangulation;
typedef Triangulation::Face_handle Face_handle;
typedef Triangulation::Vertex_handle Vertex_handle;

typedef K::Point_2 P;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m,r;
		cin>>n>>m>>r;

		double dist = (double)r * (double)r;
		vector<P> station;
		map<P,int> ids;
		int i;
		for(i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			P p(x,y);
			station.push_back(p);
			ids.insert(make_pair(p,i));
		}

		Triangulation t;
		t.insert(station.begin(),station.end());

		Graph G(n);
		for(auto it = t.finite_vertices_begin();it!=t.finite_vertices_end();it++){
			auto vc = t.incident_vertices(it);
			do{
				if(squared_distance(it->point(),vc->point())<=dist){
					int u=ids.find(it->point())->second;
					int v=ids.find(vc->point())->second;
					if(u>v)
						add_edge(u,v,G);
				}
			}while(++vc!=t.incident_vertices(it));
		}

		bool interference=!is_bipartite(G);
		if(!interference){
			for(auto it = t.finite_vertices_begin(); it!=t.finite_vertices_end(); it++){
				auto vc = t.incident_edges(it);
				vector<P> edgepts;
				do{
					if(t.is_infinite(vc))
						continue;

					auto f = vc->first;
					auto p = f->vertex(f->ccw(vc->second))->point();
					for(auto ep:edgepts){
						if(squared_distance(p,ep)<=dist){
							int u = ids.find(p)->second;
							int v = ids.find(ep)->second;
							add_edge(u,v,G);
						}
					}
					edgepts.push_back(p);
				}while(++vc!=t.incident_edges(it));
			}
			interference = !is_bipartite(G);
		}

		vector<int> component(num_vertices(G));
		connected_components(G,&component[0]);

		for(i=0;i<m;i++){
			int a,b,c,d;
			cin>>a>>b>>c>>d;

			if(interference){
				cout<<"n";
				continue;
			}

			P p(a,b), q(c,d);
			if(squared_distance(p,q)<=dist){
				cout<<"y";
				continue;
			}

			auto nearestp = t.nearest_vertex(p)->point();
			int compp = component[ids.find(nearestp)->second];

			auto nearestq = t.nearest_vertex(q)->point();
			int compq = component[ids.find(nearestq)->second];

			if(squared_distance(p,nearestp)<=dist && squared_distance(q,nearestq)<=dist && compp==compq){
				cout<<"y";
				continue;
			}
			cout<<"n";
		}
		cout<<endl;
	}
}