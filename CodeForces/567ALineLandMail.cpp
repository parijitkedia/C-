#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<arr[1]-arr[0]<<" "<<arr[n-1]-arr[0]<<endl;
	for(i=1;i<n-1;i++){
		cout<<min(arr[i+1]-arr[i],arr[i]-arr[i-1])<<" "<<max(arr[n-1]-arr[i],arr[i]-arr[0])<<endl;
	}
	cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0]<<endl;
}
