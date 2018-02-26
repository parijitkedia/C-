#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int i;
	while(t--){
		cin>>n;
		inr arr[n];
		int res[500];
		for(i=1;i<=500;i++){
			res[i]=0;
		}
		for(i=1;i<=n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);
		for(i=0;i<n;i++){
			res[arr[i]]
		}
	}
}
