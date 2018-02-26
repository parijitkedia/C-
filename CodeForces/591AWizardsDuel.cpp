#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int l;
	cin>>l;
	int p,q;
	cin>>p>>q;

	int a = p+q;
	double t = 1.0*l/a;
	cout<<fixed<<setprecision(6)<<t*p<<endl;
}
