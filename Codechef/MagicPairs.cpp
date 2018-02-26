#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int arr[n];
		long long int i,j;

		for(i=0;i<n;i++)
			cin>>arr[i];

		cout<<n*(n-1)/2<<endl;
	}
}
