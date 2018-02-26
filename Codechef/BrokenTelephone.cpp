#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		long long int arr[n],i;

		for(i=1;i<=n;i++){
			cin>>arr[i];
		}
		int ctr=0;
		for(i=1;i<=n;i++){
			if(i>1){
				if(arr[i]!=arr[i-1]){
					ctr++;
					continue;
				}
			}
			if(i<n){
				if(arr[i]!=arr[i+1]){
					ctr++;
					continue;
				}
			}
		}
		cout<<ctr<<endl;
	}
}