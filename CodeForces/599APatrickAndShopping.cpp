#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int d1,d2,d3;
	cin>>d1>>d2>>d3;

	int ans1=min(d1+d2+d3,2*(d1+d2));
	int ans2=min(2*(d1+d3),2*(d2+d3));

	if(ans1>ans2)
		cout<<ans2<<endl;
	else
		cout<<ans1<<endl;
}
