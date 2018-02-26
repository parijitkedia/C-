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

	lli val[n];

	for(i=0;i<n;i++){
		if(i==n-1){
			val[i]=arr[i];
		}else{
			val[i]=arr[i]+arr[i+1];
		}
	}

	for(i=0;i<n;i++){
		cout<<val[i]<<" ";
	}
	cout<<endl;
}