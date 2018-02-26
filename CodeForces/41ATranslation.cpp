#include <iostream>
#include <string>

using namespace std;

int main(){

	string s;
	string t;
	string rev="";
	cin>>s>>t;
	int i;
	for(i=s.size()-1;i>=0;i--){
		rev=rev+s[i];
	}

	if(rev.compare(t)==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
