#include <iostream>

using namespace std;

int main(){
	long long int n;
	cin>>n;
	long long int arr[n];
	long long int i,j;
	long long int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			sum+=arr[i]&arr[j];
		}
	}
	cout<<sum<<endl;

}
