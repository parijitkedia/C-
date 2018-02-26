#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K> Triangulation;

typedef K::Point_2 P;

struct participants{
	long x;
	long y;
	long r;
};

struct lamps{
	long x;
	long y;
};

vector<int> winners(vector<P>& lamp, vector<pair<P,long> >& part, int id, int m,long h){
	Triangulation t;
	t.insert(lamp.begin(), lamp.begin()+id+1);

	int i;
	vector<int> ans;
	for(i=0;i<m;i++){
		P nearest = t.nearest_vertex(part[i].first)->point();
		double dist = squared_distance(nearest,part[i].first);
		if(dist >= (h+part[i].second)*(h+part[i].second)){
			ans.push_back(i);
		}
	}
	return ans;
}

bool hits(vector<P>& lamp, vector<pair<P,long> >& part, int id, int m,long h){
	Triangulation t;
	t.insert(lamp.begin(), lamp.begin()+id+1);

	int i;
	for(i=0;i<m;i++){
		P nearest = t.nearest_vertex(part[i].first)->point();
		double dist = squared_distance(nearest,part[i].first);
		if(dist >= (h+part[i].second)*(h+part[i].second)){
			return false;
		}
	}
	return true;
}

void solve(int m,int n, vector<participants>& ps, long h, vector<lamps>& ls){
	int i,j;
	vector<pair<P,long> > part;
	for(i=0;i<m;i++){
		long x = ps[i].x;
		long y = ps[i].y;
		long r = ps[i].r;
		P p(x,y);
		part.push_back(make_pair(p,r));
	}

	vector<P> lamp; 
	for(i=0;i<n;i++){
		long x = ls[i].x;
		long y = ls[i].y;
		P p(x,y);
		lamp.push_back(p);
	}

	Triangulation t;
	t.insert(lamp.begin(),lamp.end());

	vector<int> ans;

	for(i=0;i<m;i++){
		P nearest = t.nearest_vertex(part[i].first)->point();
		double dist = squared_distance(nearest,part[i].first);
		if(dist>= (h+part[i].second)*(h+part[i].second)){
			ans.push_back(i);
		}
	}

	if(ans.size()>0){
		for(i:ans){
			cout<<i<<" ";
		}
	}else{
		vector<int> sol = winners(lamp,part,0,m,h);
		if(sol.size()>0){
			int low=0;
			int high=n-1;
			while(low<high-1){
				int mid = low + (high-low)/2;
				if(hits(lamp,part,mid,m,h)){
					high=mid;
				}else{
					low=mid;
				}
			}
			vector<int> w = winners(lamp,part,low,m,h);
			for(i:w){
				cout<<i<<" ";
			}
		}else{
			for(i=0;i<m;i++){
				cout<<i<<" ";
			}
		}
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;

		vector<participants> ps(m);
		int i;
		for(i=0;i<m;i++){
			cin>>ps[i].x;
			cin>>ps[i].y;
			cin>>ps[i].r;
		}

		long h;
		cin>>h;

		vector<lamps> ls(n);
		for(i=0;i<n;i++){
			cin>>ls[i].x;
			cin>>ls[i].y;
		}
		solve(m,n,ps,h,ls);
	}
}

/*int ctr=0;
	for(i=0;i<m;i++){
		P nearest = t.nearest_vertex(part[i].first)->point();
		double dist = squared_distance(nearest,part[i].first);
		if(dist>= (h+part[i].second)*(h+part[i].second)){
			cout<<i<<" ";
		}else{
			ctr++;
		}
	}

	if(ctr==m){
		vector<vector<int> > rounds(n,vector<int>());
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				long dist = squared_distance(lamp[j],part[i].first);
				if(dist< (h+part[i].second)*(part[i].second)){
					rounds[j].push_back(i);
					break;
				}
			}
		}

		for(j=n-1;j>=0;j--){
			if(rounds[j].size()>0){
				for(i=0;i<rounds[j].size();i++){
					cout<<rounds[j][i]<<" ";
				}
				break;
			}
		}
	} 

	vector<int> ans(m,numeric_limits<int>::max());

	for(i=0;i<m;i++){
		P nearest = t.nearest_vertex(part[i].first)->point();
		double dist = squared_distance(nearest,part[i].first);

		if( dist >= (h+part[i].second)*(h+part[i].second))
			continue;

		for(j=0;j<n;j++){
			double d = squared_distance(part[i].first,lamp[j]);
			if( (h+part[i].second)*(h+part[i].second) > d ){
				ans[i]=j;
				break;
			}
		}
	}

	int max = *max_element(ans.begin(),ans.end());
	for(i=0;i<m;i++){
		if(ans[i]==max)
			cout<<i<<" ";
		cout<<endl;
	}*/