#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int ctr=0;
	do{
		a=3*a;
		b=2*b;
		ctr++;
	}while(a<=b);
	cout<<ctr<<endl;
}
