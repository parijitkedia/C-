#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;
		lli arr[n];
		lli i,flag=0;
		lli gcd=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			gcd=__gcd(gcd,arr[i]);
		}

		if(gcd==1){
			cout<<-1<<endl;
		}else{
			for(i=2;i<=floor(sqrt(gcd));i++){
				if(gcd%i==0){
					flag=1;
					break;
				}
			}

			if(flag==1)
				cout<<i<<endl;
			else
				cout<<gcd<<endl;
		}
	}
}
