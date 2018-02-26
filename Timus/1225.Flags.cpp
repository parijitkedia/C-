#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long int arr[46];
	arr[1]=2;
	arr[2]=2;
	arr[3]=4;
	for(int i=4;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	cout<<arr[n]<<endl;
}
