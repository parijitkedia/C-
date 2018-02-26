#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	int arr[n+1];
	int val[n+1];
	arr[0]=0,val[0]=0;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		val[i]=0;
	}

	for(i=1;i<=n;i++){
		val[arr[i]]=1;
	}

	for(i=1;i<=n;i++){
		if(val[i]==0)
			cout<<i<<" ";
	}

}
