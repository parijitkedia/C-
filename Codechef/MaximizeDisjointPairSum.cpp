#include <iostream>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n,d;
		cin>>n>>d;

		lli i;
		lli arr[n];

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);
        lli sum=0;
		for(i=n-1;i>0;i--){
			if(arr[i]-arr[i-1]<d){
				sum+=arr[i]+arr[i-1];
				i--;
			}
		}
		cout<<sum<<endl;
	}
}
