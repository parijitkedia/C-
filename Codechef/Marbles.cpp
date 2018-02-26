#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int lli;

using namespace std;

lli fact(lli n,lli r){
	lli i,j;
	lli res=1;
	if(r>n-r)
		r=n-r;

	for(i=0;i<r;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	lli n,k;
	while(t--){
		cin>>n>>k;
		lli ans = fact(n-1,k-1);
		cout<<ans<<endl;
	}
}
