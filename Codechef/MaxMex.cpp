#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n,k;
		cin>>n>>k;
		lli arr[n];
		lli i,a=k;
		lli maxv = -1;
		for(i=0;i<n;i++){
			cin>>arr[i];
			maxv = max(maxv,arr[i]);
		}

		sort(arr,arr+n);

		vector<lli> val;

		for(i=0;i<=maxv+2+k;i++){
			val.push_back(0);
		}

		for(i=0;i<n;i++){
			val[arr[i]]=1;
		}

		for(i=0;i<=maxv+2+a;i++){
			if(k==0)
				break;
			if(val[i]==0){
				val[i]=1;
				k--;
			}
		}

		for(i=0;i<=maxv+2+a;i++){
			if(val[i]==0){
				cout<<i<<endl;
				break;
			}
		}
	}
}