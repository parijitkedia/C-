#include <iostream>
#include <string>

using namespace std;

int main(){

	string a,b;
	cin>>a>>b;
	string ans;

	int i;
	for(i=0;i<a.length();i++){
		if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1'))
			ans=ans+'1';
		else
			ans=ans+'0';
	}
	cout<<ans<<endl;
}
