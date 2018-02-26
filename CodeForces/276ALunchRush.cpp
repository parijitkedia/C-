#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	lli n,k;
	cin>>n>>k;

	lli i,f,t;
	lli ans=-1000000000;
	for(i=0;i<n;i++){
		cin>>f>>t;
		if(t>k){
			ans = max(ans,f-(t-k));
		}else{
			ans = max(ans,f);
		}
	}
	cout<<ans<<endl;
}
