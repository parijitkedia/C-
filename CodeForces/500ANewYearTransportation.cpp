#include <iostream>

using namespace std;

int main(){

	int n,t;

	cin>>n>>t;
	int arr[n-1];
	int i;
	int sum,flag;
	for(i=1;i<=n-1;i++)
		cin>>arr[i];
    
	for(i=1;i<t;i=i+arr[i]){
	}

	if(i==t)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
