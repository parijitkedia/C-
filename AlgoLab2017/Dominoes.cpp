#include <iostream>
#include <cmath>

using namespace std;

int solve(int n, int arr[]){
	int i,l=0,flag=0;
	for(i=0;i<n;i++){
		l = max(i+arr[i]-1,l);
		if(i>=l){
			flag=1;
			break;
		}
	}
	if(flag==1)
		return l+1;
	else
		return n;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int i;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<solve(n,arr)<<endl;
	}
}
