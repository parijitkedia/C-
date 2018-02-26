#include <iostream>
#include <vector>
#include <climits>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;

P q0, q1, q2, q3, q4, q5;

bool inside_map(P& p){
	return (left_turn(q0,q1,p) || collinear(q0,q1,p)) 
	&& (left_turn(q2,q3,p) || collinear(q2,q3,p)) 
	&& (left_turn(q4,q5,p) || collinear(q4,q5,p));
}

void vsum(vector<int>& a, vector<int>& b){
	int i;
	for(i=0;i<a.size();i++){
		a[i]+=b[i];
	}
}

void vsub(vector<int>& a, vector<int>& b){
	int i;
	for(i=0;i<a.size();i++){
		a[i]-=b[i];
	}
}

bool all_contained(vector<int>& contained){
	return std::all_of(contained.begin(),contained.end(),[](int i){return i>0;});
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;

		vector<P> legs(m);
		int i,j;
		for(i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			P p(x,y);
			legs.push_back(p);
		}

		vector<vector<int> > cont_leg;
		for(i=0;i<n;i++){
			int x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
			cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5;

			q0 = P(x0, y0); 
			q1 = P(x1, y1); 
			q2 = P(x2, y2); 
			q3 = P(x3, y3); 
			q4 = P(x4, y4);
			q5 = P(x5, y5);

			if(right_turn(q0,q1,q2))
				swap(q0,q1);
			if(right_turn(q2,q3,q4))
				swap(q2,q3);
			if(right_turn(q4,q5,q0))
				swap(q4,q5);

			vector<int> contained(m-1,0);
			for(j=0;j<legs.size()-1;j++){
				if(inside_map(legs[j]) && inside_map(legs[j+1])){
					contained[j]=1;
				}
			}
			cont_leg.push_back(contained);	
		}

		i=0;
		vector<int> contained(m-1,0);
		int minv = numeric_limits<int>::max();
		for(j=i;j<n;j++){
			vsum(contained,cont_leg[j]);
			while(all_contained(contained)){
				minv = std::min(minv,j-i+1);
				vsub(contained,cont_leg[i]);
				++i;
			}
		}
		cout<<minv<<endl;
	}
}