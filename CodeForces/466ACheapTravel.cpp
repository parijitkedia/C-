#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,m,a,b;

	cin>>n>>m>>a>>b;

	int s=a*n;
	int m1=(n/m)*b;
	m1=m1 + min((n%m)*a,b);
	if(s<m1)
		cout<<s<<endl;
	else
		cout<<m1<<endl;
}
