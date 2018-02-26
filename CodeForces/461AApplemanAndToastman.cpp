#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(){
	lli n;
	cin>>n;
	lli arr[n];
	lli i,a;
	lli sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	sort(arr,arr+n);
	for(i=1;i<=n;i++){
		sum+=(i+1)*arr[i-1];
	}
	sum-=arr[n-1];
	cout<<sum<<endl;
}