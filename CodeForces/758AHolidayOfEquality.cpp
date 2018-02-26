#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];
	int i;
	int maxv=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		maxv=max(maxv,arr[i]);
	}
	int sum=0;
	for(i=0;i<n;i++){
		sum+=maxv-arr[i];
	}
	cout<<sum<<endl;
}