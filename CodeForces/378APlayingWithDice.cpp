#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int i;
	int f=0,m=0,s=0;
	for(i=1;i<=6;i++){
		if(abs(a-i)<abs(b-i))
			f++;
		else if(abs(a-i)>abs(b-i))
			s++;
		else
			m++;
	}
	cout<<f<<" "<<m<<" "<<s<<endl;
}