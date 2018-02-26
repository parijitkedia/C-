#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n,k;
		cin>>n>>k;

		lli i;
		lli a[n];
		lli b[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		for(i=0;i<n;i++){
			cin>>b[i];
		}
		lli maxv=-1;
		for(i=0;i<n;i++){
			lli q = k/a[i];
			maxv=max(q*b[i],maxv);
		}
		cout<<maxv<<endl;
	}
}
