#include <iostream>

using namespace std;

int main(){
	int n,h;
	cin>>n>>h;

	int arr[n];
	int i;
	int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]<=h)
			sum+=1;
		else
			sum+=2;
	}
	
	cout<<sum<<endl;
}