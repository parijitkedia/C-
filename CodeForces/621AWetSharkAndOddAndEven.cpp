#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long int arr[n];
	int i,ans=1;
	long long int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);

	if(sum%2==0){
		cout<<sum<<endl;
	}else{
		for(i=0;i<n;i++){
			sum-=arr[i];
			if(sum%2==0){
				cout<<sum<<endl;
				break;
			}
		}
	}

}
