#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	lli n,i,a,sum;

	while(t--){
		cin>>n;
		sum=n*(n+1)/2;
		for(i=0;;i++){
			if(pow(2,i)<=n){
				sum-=2*pow(2,i);
			}
			if(pow(2,i)>n)
				break;
		}
		cout<<sum<<endl;
	}
}
