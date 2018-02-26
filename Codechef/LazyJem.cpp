#include <iostream>

using namespace std;

int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int n,b,m;
		cin>>n>>b>>m;
		long long int res=0;
		while(n){
			long long int p=(n+1)/2;
			res+=p*m;
			n-=p;
			if(n)
				res+=b;
			m=m*2;
		}
        cout<<res<<endl;
	}
}
