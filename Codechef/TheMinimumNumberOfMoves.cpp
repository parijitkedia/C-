#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int i;
		int minv=999999,sum=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
			minv=min(minv,arr[i]);
		}
		cout<<sum-n*minv<<endl;
	}
}
