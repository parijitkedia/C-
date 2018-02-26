#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int i;
		int sum=0;

		for(i=0;i<n;i++)
			cin>>arr[i];

		sort(arr,arr+n);
		reverse(arr,arr+n);
		for(i=0;i<n;i++){
			if(i%4<2)
				sum+=arr[i];
		}
		cout<<sum<<endl;
	}
}
