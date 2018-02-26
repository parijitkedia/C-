#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long int arr[n],gcd,mul=1;
	int i;
	cin>>arr[0];
	mul*=arr[0];
	gcd=arr[0];
	for(i=1;i<n;i++){
		cin>>arr[i];
		mul*=arr[i];
		gcd=__gcd(arr[i],gcd);
	}
	cout<<mul<<endl;
	cout<<gcd<<endl;
	cout<<mul/gcd<<endl;
}
