#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int k2,k3,k5,k6;
	cin>>k2>>k3>>k5>>k6;
	int sum=0;

	int ans = min(k2,min(k5,k6));
	sum+=256*ans;
	k2=k2-ans;

	ans = min(k2,k3);
	sum+=32*ans;
	cout<<sum<<endl;
}
