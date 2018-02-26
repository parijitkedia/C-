#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,m;
	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;
		int arr[n];
		int i;
		int maxv=-1;
		int sum=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if((sum+m)%n==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
