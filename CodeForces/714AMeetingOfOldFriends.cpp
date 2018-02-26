#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	lli l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;

	lli maxv = max(l1,l2);
	lli minv = min(r1,r2);
	if(maxv>minv){
		cout<<0<<endl;
	}else{
		if(k>=maxv && k<=minv){
			cout<<minv-maxv<<endl;
		}else{
			cout<<minv-maxv+1<<endl;
		}
	}
}