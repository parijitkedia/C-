#include <iostream>
#include <vector>
#include <cmath>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Ray_2 R;

bool comp(pair<R,int>& a, pair<R,int>& b){
	return a.first.source().y() > b.first.source().y();
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int i,j;
		vector<P> start(n);
		vector<P> end(n);
		vector<pair<R,int> > ray(n);
		for(i=0;i<n;i++){
			long y0,x1,y1;
			cin>>y0>>x1>>y1;

			start[i]=P(0,y0);
			end[i]=P(x1,y1);
			ray[i]=make_pair(R(start[i],end[i]),i);
		}

		sort(ray.begin(),ray.end(),comp);
		vector<pair<int,int> >ans;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(do_intersect(ray[i].first,ray[j].first)){
					auto compare = compare_slopes(ray[i].first.supporting_line(),ray[j].first.supporting_line());
					if(compare == SMALLER){
						pair<int,int> p = make_pair(ray[i].second,ray[j].second);
						ans.push_back(p);
					}
				}
			}
		}

		vector<int> res;
		for(auto k:ans)
			res.push_back(k.second);

		sort(res.begin(),res.end());
		i=0;
		for(j:res){
			while(i<j){
				cout<<i<<" ";
				i++;
			}
			if(i==j)
				i++;
		}
		while(i<n){
			cout<<i<<" ";
			i++;
		}
	}
}