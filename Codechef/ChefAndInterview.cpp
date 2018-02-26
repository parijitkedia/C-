#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;

		lli i,sum=0;
		for(i=1;i*i<=n;i++){
			if(n%i==0){
				sum+=i;
				if(i!=n/i){
					sum+=n/i;
				}
			}
		}
		cout<<sum<<endl;
	}
}
