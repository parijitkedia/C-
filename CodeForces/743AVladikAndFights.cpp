#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	string str;
	cin>>str;

	if(str[a-1]==str[b-1])
		cout<<0<<endl;
	else
		cout<<1<<endl;
}