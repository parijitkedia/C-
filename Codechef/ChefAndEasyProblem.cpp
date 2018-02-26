#include <iostream>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;

		lli arr[n],i;
		
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

        lli sum=0;
		for(i=n-1;i>=0;i-=2){
			sum+=arr[i];
		}
		cout<<sum<<endl;
	}
}
