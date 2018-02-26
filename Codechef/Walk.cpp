#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i,maxv=0;
		int arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
			maxv=max(maxv,arr[i]+i);
		}
		cout<<maxv<<endl;
	}
}
