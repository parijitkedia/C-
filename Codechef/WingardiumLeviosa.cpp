#include <iostream>
#include <vector>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	lli n,m;
	cin>>n>>m;

	vector<lli> arr;

	lli i,j;
	lli x;
	for(i=1;i<=n;i++){
		lli x = min(i,n-i);
		arr.push_back(x);
	}

	lli q,a,b,k;

	for(i=0;i<m;i++){
		cin>>q>>a>>b>>k;
		if(q==0){
			for(j=a-1;j<b;j++){
				arr[j]+=k;
			}
		}
		if(q==1){
			for(j=a-1;j<b;j++){
				arr[j]-=k;
			}
		}
	}
	lli minv=arr[0];
	lli maxv=arr[0];
	for(i=1;i<n;i++){
		minv = min(minv,arr[i]);
		maxv = max(maxv,arr[i]);
	}
	cout<<minv<<" "<<maxv<<endl;
}
