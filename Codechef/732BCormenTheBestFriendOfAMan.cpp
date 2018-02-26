#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];

	int i;
	int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=1;i<n;i++){
		if(arr[i]+arr[i-1]<=k){
			sum+=k-arr[i]-arr[i-1];
			arr[i]=k-arr[i-1];
		}
	}
	cout<<sum<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}