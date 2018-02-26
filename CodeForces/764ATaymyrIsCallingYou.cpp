#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
	int n,m,z;
	cin>>n>>m>>z;
	int hcf = __gcd(n,m);
	int lcm = n*m/hcf;
	cout<<z/lcm<<endl;
}
