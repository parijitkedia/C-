#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int i,j;
		long long int minv=0,ans=0;
		for(i=ceil(sqrt(n));i>0;i--){
			if(n%i==0){
				minv=n/i;
				ans=abs(minv-i);
				break;
			}
		}
		cout<<ans<<endl;
	}
}
