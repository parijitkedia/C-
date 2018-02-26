#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(){
	lli n;
	cin>>n;

	lli arr[n],sum;
	lli i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr,arr+n);
	lli ctr=0;
	sum=0;
	for(i=0;i<n;i++){
		if(arr[i]>=sum){
			ctr++;
			sum+=arr[i];
		}
	}
	cout<<ctr<<endl;
}
