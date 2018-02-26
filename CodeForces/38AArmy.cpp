#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;
	int a,b;

	for(i=0;i<n-1;i++){
		cin>>arr[i];
	}

	cin>>a>>b;
	int sum=0,k=0;
	do{
		sum+=arr[a-1];
		k++;
		a++;
	}while(a!=b);
	cout<<sum<<endl;

}
