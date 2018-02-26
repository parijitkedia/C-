#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int n;
	cin>>n;
	long long int i,a,b;
	long double ans;
	for(i=1;i<=n;i++){
		cin>>a;
        b = 8*a-7;
		ans = sqrt(b);
		if(floor(ans)==ans)
			cout<<1<<" ";
		else
			cout<<0<<" ";
	}
	cout<<endl;
}
