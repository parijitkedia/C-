#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;
	int count=0;
	for(i=0;i<n;i++)
		cin>>arr[i];

	for(i=0;i<n;i++){
		if(arr[i]-arr[i+1]==0)
			continue;
		else
			count++;
	}
	cout<<count<<endl;
}
