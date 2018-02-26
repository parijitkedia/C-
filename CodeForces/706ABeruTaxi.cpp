#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	int i;
	int x,y,v;
	double z = 100000;
	for(i=0;i<n;i++){
		cin>>x>>y>>v;
		double ans = sqrt( (a-x)*(a-x) + (b-y)*(b-y) );
		double res = ans/v;
		z = min(z,res);
	}
	cout<<fixed<<setprecision(10)<<z<<endl;
}
