#include <iostream>
#include <vector>
#include <iomanip>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Segment_2 S;
typedef K::Ray_2 R;

void solve(vector<P>& arr, int n){
	vector<int> ans;
	int k=0;
	for(auto i:arr){
		for(auto j:arr){
			if(*i==*j){
				continue;
			}else{
				if(intersect(i,j)){
					ans.push_back(k);
					break;
				}
			}
		}
		k++;
	}
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<R> arr;
		int i;
		for(i=0;i<n;i++){
			long y0,x1,y1;
			cin>>y0>>x1>>y1;

			P p(0,y0), q(x1,y1);
			R r(p,q);
			arr.push_back(r);
		}
		solve(arr,n);
	}
}