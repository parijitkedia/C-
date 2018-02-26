#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[2*n];
	int val[n];
	int i;
	for(i=1;i<=2*n;i++){
		cin>>arr[i];
	}

	for(i=1;i<=n;i++){
		val[i]=0;
	}

	int a,maxv=-1,ctr=0;
	for(i=1;i<=2*n;i++){
		a=arr[i];
		val[a]++;
		ctr++;
		if(val[a]==2){
			//cout<<i<<endl;
			val[a]=0;
		//	cout<<i<<endl;
			ctr-=2;
		}
		maxv = max(maxv,ctr);
		//cout<<ctr<<" "<<maxv<<endl;
	}
	cout<<maxv<<endl;
}
