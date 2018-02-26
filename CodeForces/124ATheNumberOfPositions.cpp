#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;

	cout<<min(n-a,b+1)<<endl;
}