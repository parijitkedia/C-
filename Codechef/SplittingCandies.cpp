#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n,k;
		cin>>n>>k;
		if(n==0 && k==0)
			cout<<0<<" "<<0<<endl;
		else if(k==0 && n>0)
			cout<<0<<" "<<n<<endl;
		else
			cout<<n/k<<" "<<n%k<<endl;
	}
}