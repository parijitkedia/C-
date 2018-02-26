#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	string str;
	cin>>str;
	
	int a = str.find("AB");
	int b = str.find("BA");
	if(a!=-1 && str.find("BA",a+2)!=-1 || b!=-1 && str.find("AB",b+2)!=-1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	
}
