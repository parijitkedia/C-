#include <iostream>
#include <vector>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/basic.h>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>

using namespace std;
using namespace CGAL;

#include <CGAL/Gmpz.h>
typedef Gmpzf ET;

typedef Quadratic_program<ET> Program;
typedef Quadratic_program_solution<ET> Solution;
typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;
typedef K::FT F;

struct lamp{
	int x;
	int y;
};

struct stamp{
	int x;
	int y;
	int maxint;
};

struct wall{
	int a;
	int b;
	int c;
	int d;
};

bool solve(int l, int s, int w, vector<lamp>& lamps, vector<stamp>& stamps, vector<wall>& walls){
	vector<P> ls;
	int i,j,k;
	for(i=0;i<l;i++){
		lamp& la=lamps[i];
		P p(la.x,la.y);
		ls.push_back(p);
	}

	vector<P> ss;
	for(i=0;i<s;i++){
		stamp& st=stamps[i];
		P p(st.x,st.y);
		ss.push_back(p);
	}

	vector<S> ws;
	for(i=0;i<w;i++){
		wall& wa=walls[i];

		P p(wa.a,wa.b);
		P q(wa.c,wa.d);
		S seg(p,q);
		ws.push_back(seg);
	}

	Program p(SMALLER, true, 1, true, (1<<12));

	for(j=0;j<s;j++){
		for(i=0;i<l;i++){
			S r(ss[j],ls[i]);

			bool blocked=false;
			for(k=0;k<w;k++){
				if(do_intersect(ws[k],r)){
					blocked=true;
					break;
				}
			}
			if(blocked)
				continue;
			F invdist = 1/r.squared_length();
			double idist = to_double(invdist);
			p.set_a(i,j,idist);
			p.set_a(i,j+s,idist);
		}
		p.set_r(j,SMALLER);
		p.set_b(j,stamps[j].maxint);

		p.set_r(j+s,LARGER);
		p.set_b(j+s,1);
	}
	Solution sol = solve_linear_program(p,ET());
	return !sol.is_infeasible();
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int l,s,w;
		cin>>l>>s>>w;

		int i;
		vector<lamp> ls(l);
		for(i=0;i<l;i++){
			cin>>ls[i].x;
			cin>>ls[i].y;
		}

		vector<stamp> ss(s);
		for(i=0;i<s;i++){
			cin>>ss[i].x;
			cin>>ss[i].y;
			cin>>ss[i].maxint;
		}

		vector<wall> ws(w);
		for(i=0;i<w;i++){
			cin>>ws[i].a;
			cin>>ws[i].b;
			cin>>ws[i].c;
			cin>>ws[i].d;
		}

		if(solve(l,s,w,ls,ss,ws))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
