#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	if(m>n)
		cout<<-1<<endl;
	else{
		if(n%2==0){
			int a = n/2;
			if(a%2==0){
				cout<<a<<endl;
			}else{
				n=n-2;
				cout<<n/2+2<<endl;
			}
		}else{
			n=n-1;
			cout<<n/2+1<<endl;
		}
	}
}