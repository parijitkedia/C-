#include <iostream>

typedef long long int lli;

using namespace std;

lli check(lli n){
	lli i;
	lli sum=0;
	for(i=1;i<=n/2;i++){
		if(n%i==0 && i%2!=0){
			sum+=i;
		}
	}
	if(n%2!=0)
		sum+=n;
	return sum;
}

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli l,r;
		cin>>l>>r;

		lli i,ans=0;
		for(i=l;i<=r;i++){
			lli a = check(i);
			//cout<<a<<endl;
			ans+=a;
		}
		cout<<ans<<endl;
	}
}
