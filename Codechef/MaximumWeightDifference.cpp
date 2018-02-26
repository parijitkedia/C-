#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		int i;
		int sum=0,sum1=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		int m=max(k,n-k);
		sort(arr,arr+n,greater<int>());

		for(i=0;i<m;i++)
			sum1+=arr[i];

		cout<<sum1-(sum-sum1)<<endl;
	}
}
