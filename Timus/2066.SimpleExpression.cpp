#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(b==0 || b==1 || c==1)
		cout<<a-b-c<<endl;
	else
		cout<<a-(b*c)<<endl;
}
