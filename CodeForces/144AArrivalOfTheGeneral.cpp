#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	int arr[n],sum;
	int maxv=0,minv=101;
	int posmax=n,posmin=0;
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}

	for(i=1;i<=n;i++){
		if(arr[i]>maxv){
			maxv=arr[i];
			posmax=i;
		}
		if(arr[i]<=minv){
			minv=arr[i];
			if(i<posmin){

			}else{
				posmin=i;
			}
		}
	}

	if(posmax<posmin){
		sum=posmax-1 + n-posmin;
	}else{
		sum=posmax-1 + n-posmin-1;
	}
	cout<<sum<<endl;
}