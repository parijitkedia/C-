#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long int lli;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	
	
	lli t;
	cin>>t;

	while(t--){
		lli n,k;
		cin>>n>>k;

		lli ans = pow(n,n);

		lli i;
		lli dig,rev;
		vector<lli> val;
		for(i=ans;i>0;i=i/10){
			dig=i%10;
			val.push_back(dig);
		}

		reverse(val.begin(),val.end());

		for(i=0;i<k;i++){
			cout<<val[i];
		}
		cout<<" ";
		for(i=val.size()-k;i<val.size();i++){
			cout<<val[i];
		}
		cout<<endl;
	}
}
