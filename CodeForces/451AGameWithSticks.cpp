#include <iostream>

using namespace std;

int main(){

	int n,m;

	cin>>n>>m;
	int val=min(m,n);

	if(val%2!=0)
		cout<<"Akshat"<<endl;
	else
		cout<<"Malvika"<<endl;
}
