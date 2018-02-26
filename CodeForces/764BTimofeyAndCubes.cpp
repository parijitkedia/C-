#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	lli n;
	cin>>n;

	lli arr[n];
	lli i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	i=0;
	lli temp;
	while(i<n/2){
		temp = arr[n-i-1];
		arr[n-i-1]=arr[i];
		arr[i] = temp;
		i+=2;
	}
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
