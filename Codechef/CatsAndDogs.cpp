#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int c,d,l;
		cin>>c>>d>>l;
		if(l%4==0 && (c+d)*4>=l)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}