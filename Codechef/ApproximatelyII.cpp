#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n,k;
		cin>>n>>k;

		lli arr[n];
		lli i,j,diff,minv=10000000000,ctr=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				diff = abs(arr[i]+arr[j]-k);
				if(diff<minv){
					minv=diff;
					ctr=1;
				}else if(diff==minv){
					ctr++;
				}
			}
		}
		cout<<minv<<" "<<ctr<<endl;
	}
}
