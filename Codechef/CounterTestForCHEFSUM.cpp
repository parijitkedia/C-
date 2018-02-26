#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		//lli a = 100000;

		int i;
		for(i=1;i<=n;i++){
			lli a = 99001 + rand()%(1000);
			cout<<a<<" ";
		}
		cout<<endl;
	}
}
