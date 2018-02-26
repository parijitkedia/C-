#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int m = max(3*a/10,a - a*c/250);
	int v = max(3*b/10,b - b*d/250);
	if(m>v)
		cout<<"Misha"<<endl;
	else if(m<v)
		cout<<"Vasya"<<endl;
	else
		cout<<"Tie"<<endl;
}