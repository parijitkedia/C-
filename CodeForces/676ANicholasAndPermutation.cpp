#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i,a;
	int posmin,posmax;
	for(i=1;i<=n;i++){
		cin>>a;
		if(a==1){
			posmin=i;
		}
		if(a==n){
			posmax=i;
		}
	}

	int ans = max( abs(posmin-1), max( abs(posmax-1), max( abs(posmin-n), abs(posmax-n) ) )  );
	cout<<ans<<endl;
}