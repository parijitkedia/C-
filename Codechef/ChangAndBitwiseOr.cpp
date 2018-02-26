#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	long long int i,n,ans=0;	
	while(t--){
		ans=0;
		cin>>n;
		long long int arr[n];

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		for(i=0;i<n;i++){
			ans = ans | arr[i];
		}
		cout<<ans<<endl;
	}
}