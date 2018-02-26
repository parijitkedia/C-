#include <iostream>

using namespace std;

int main(){

	std::ios_base::sync_with_stdio(false);

	long long n,k,j=0;

	cin>>n>>k;
	long long pos;

	n=(n+1)/2;
	if(k<=n)
		pos=2*k-1;
	else
		pos=2*(k-n);

	cout<<pos<<endl;
}
