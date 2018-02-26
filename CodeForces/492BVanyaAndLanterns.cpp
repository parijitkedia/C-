#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	long long int n,l;
	cin>>n>>l;
	int i;
	int arr[n];
	int diff[n];
	int maxv=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(i=1;i<n;i++){
		diff[i]=arr[i]-arr[i-1];
		if(diff[i]>maxv)
			maxv=diff[i];
	}

	int first = arr[0]-0;
	int last = l-arr[n-1];
	float ans = max(maxv,max(last,first)*2);
	cout<<fixed<<setprecision(9)<<ans/2<<endl;
}
