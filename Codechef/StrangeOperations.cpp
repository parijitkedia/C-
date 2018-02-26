#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	long long int n,k;
	long long int i;
    long long int sum=0;
	while(t--){
		cin>>n>>k;
		long long int arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(k==1){
			if(sum%2==0)
				cout<<"odd"<<endl;
			else
				cout<<"even"<<endl;
		}
		else
			cout<<"even"<<endl;
		sum=0;
	}
}
