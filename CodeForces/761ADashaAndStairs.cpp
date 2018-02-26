#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	if(a==0 && b==0)
		cout<<"NO"<<endl;
	else if(a-b==0 || abs(a-b)==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}