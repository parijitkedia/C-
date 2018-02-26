#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;
	int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int ans=n*(n+1)/2;
	if(sum==ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
