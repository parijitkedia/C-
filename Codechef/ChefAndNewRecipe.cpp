#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int i;
		int arr[n];
		int minv = 10000,sum=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			minv = min(minv,arr[i]);
			sum+=arr[i];
		}
		sort(arr,arr+n,greater<int>());

		if(minv==1){
			cout<<-1<<endl;
		}else{
			if(minv==2){
				cout<<sum<<endl;
			}else{
				cout<<sum-arr[n-1]+2<<endl;
			}
		}
	}
}
