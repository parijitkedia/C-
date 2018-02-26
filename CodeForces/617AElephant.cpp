#include <iostream>

using namespace std;

int main(){
	long long c;
	cin>>c;

	if(c%5==0)
		cout<<c/5<<endl;
	else
		cout<<c/5+1<<endl;
}