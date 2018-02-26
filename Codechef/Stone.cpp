#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

lli check(lli arr[],lli n){
	int i;
	lli maxv=-2*(pow(10,9));
	for(i=0;i<n;i++){
		maxv=max(maxv,arr[i]);
	}
	return maxv;
}

int main(){
	lli n,k;
	cin>>n>>k;
	lli maxv=-2*(pow(10,9));
	lli arr[n];
	int i,j;
	for(i=0;i<n;i++){
		cin>>arr[i];
		maxv=max(maxv,arr[i]);
	}

	if(k==0){
		for(i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
		if(k%2==1)
			k=1;
		else
			k=2;

		for(i=0;i<k;i++){
			lli MAX = check(arr,n);
			for(j=0;j<n;j++){
				arr[j]=MAX-arr[j];
			}
		}

		for(i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;	
	}
}
