#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int i;
	int one=0;
	while(t--){
		cin>>n;
		int arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]==1)
				one++;
		}
		if(one%2!=0)
			cout<<one<<endl;
		else
			cout<<n-one<<endl;
		one=0;
	}
}