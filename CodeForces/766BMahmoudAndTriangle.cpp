#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long int arr[n],i,j;

	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int flag=0;
	sort(arr,arr+n);

	for(i=0;i<n-2;i++){
		if(arr[i]+arr[i+1]>arr[i+2]){
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}
