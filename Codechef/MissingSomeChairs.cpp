#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;

		lli mod = 1000000000+7;

		cout<<((1<<n) - 1)%mod<<endl;
	}
}
