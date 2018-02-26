#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	while(n>5){
		n=n/2-2;
	}
	if(n==1)
		cout<<"Sheldon"<<endl;
	if(n==2)
		cout<<"Leonard"<<endl;
	if(n==3)
		cout<<"Penny"<<endl;
	if(n==4)
		cout<<"Rajesh"<<endl;
	if(n==5)
		cout<<"Howard"<<endl;
}
