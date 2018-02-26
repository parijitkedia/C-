#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	if((a+b)%n==0)
		cout<<n<<endl;
	else
		cout<<abs((a+b)%n)<<endl;
}