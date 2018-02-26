#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long int> arr(n);
	int i;

	long long int maxv=-1,minv=1e9;

	for(i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>maxv)
			maxv=arr[i];
		if(arr[i]<minv)
			minv=arr[i];
	}

	int countmax=0,countmin=0;
	for(i=0;i<n;i++){
		if(arr[i]==maxv)
			countmax++;
		if(arr[i]==minv)
			countmin++;
	}
	if(maxv!=minv)
		cout<<maxv-minv<<" "<<countmin*countmax<<endl;
	else
		cout<<0<<" "<<maxv*(maxv-1)/2<<endl;
}
