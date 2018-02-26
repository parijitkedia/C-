#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;
		lli arr[n];
		lli i;
		lli sum=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}

		for(i=0;i<n;i++){
			cout<< (sum/(n-1)) - arr[i]<<" ";
		}
		cout<<endl;
	}
}