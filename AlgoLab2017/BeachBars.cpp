#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> arr(n);
		int i;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr.begin(),arr.end());

		int maxv=0;
		vector<int> pos;
		for(i=0;i<n;i++){
			int end = arr[i]+200;
			int ctr=i;
			while(ctr<n && arr[ctr]<=end){
				ctr++;
			}
			ctr=ctr-i;
			if(ctr>maxv){
				maxv=ctr;
				pos=vector<int>();
				pos.push_back(i);
			}else{
				if(ctr==maxv){
					pos.push_back(i);
				}
			}
		}
		int minv=INT_MAX;
		for(i:pos){
			int mid = (int)floor((arr[i]+arr[i+maxv-1])/2);
			minv = min(minv,max(abs(mid-arr[i]), abs(mid-arr[i+maxv-1])));
		}
		cout<<maxv<<" "<<minv<<endl;
		vector<int> sol;
		for(i:pos){
			int mid = (int)floor((arr[i]+arr[i+maxv-1])/2);
			int dist = max(abs(mid-arr[i]), abs(mid-arr[i+maxv-1]));
			if(dist==minv){
				sol.push_back(mid);
				if(abs(mid-arr[i])!=abs(mid-arr[i+maxv-1])){
					if(mid<0){
						sol.push_back(mid-1);
					}else{
						sol.push_back(mid+1);
					}
				}
			}
		}
		sort(sol.begin(),sol.end());
		for(i=0;i<sol.size();i++){
			cout<<sol[i]<<" ";
		}
		cout<<endl;
	}
}