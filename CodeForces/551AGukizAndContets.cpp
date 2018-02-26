#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];
	int i,j,a=n,b=1,ctr=0;

	int res[n];
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}

	for(i=1;i<=n;i++){
		int a=arr[i];
		for(j=1;j<=n;j++){
			if(arr[j]>a)
				ctr++;
		}
		res[i]=1+ctr;
		ctr=0;
	}

	for(i=1;i<=n;i++){
		cout<<res[i]<<" ";
	}
}