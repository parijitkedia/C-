#include <iostream>
#include <vector>
#include <map>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> Triangulation;
typedef K::Point_2 P;

typedef Gmpq ET;
typedef Quadratic_program<int> Program;
typedef Quadratic_program_solution<ET> Solution;

bool comp(pair<int,P>& a, pair<int,P>& b){
	return a.first<b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		double z;
		int u,v,w;
		cin>>z>>u>>v>>w;

		int a,g;
		cin>>a>>g;
		int i;
		vector<P> gpt(g);
		map<P,vector<int> > gangsters;

		for(i=0;i<g;i++){
			long x,y;
			cin>>x>>y;
			P p(x,y);
			gpt[i]=p;
			vector<int> g(4,0);
			cin>>g[0]>>g[1]>>g[2];
			g[3]=-1;
			gangsters[p]=g;
		}

		Triangulation t;
		t.insert(gpt.begin(),gpt.end());

		vector<pair<int,P> > agents(a);
		for(i=0;i<a;i++){
			long x,y;
			cin>>x>>y;
			P p(x,y);
			int z;
			cin>>z;
			P nearest = t.nearest_vertex(p)->point();
			agents[i]=make_pair(z,nearest);
		}

		sort(agents.begin(),agents.end(),comp);

		Program lp(SMALLER,true,0,true,24);

		for(i=0;i<a;i++){
			vector<int> gangster = gangsters[agents[i].second];

			if(gangster[3]!=-1)
				continue;
			else
				gangsters.at(agents.at(i).second).at(3)=i;

			lp.set_a(i,0,-gangster[0]);
			lp.set_a(i,1,-gangster[1]);
			lp.set_a(i,2,-gangster[2]);
			lp.set_c(i,agents[i].first);
		}
		lp.set_b(0,-u);
		lp.set_b(1,-v);
		lp.set_b(2,-w);

		Solution s = solve_linear_program(lp,ET());
		if(s.is_optimal() && to_double(s.objective_value())<=z)
			cout<<"L"<<endl;
		else
			cout<<"H"<<endl;
	}
}

