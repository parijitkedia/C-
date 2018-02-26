#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int a,b,c,d;
		cin>>a>>b>>c>>d;
		long long int g = __gcd(c,d);

		cout<<min( (a-b)%g, (b-a)%g )<<endl;
	}
	
}