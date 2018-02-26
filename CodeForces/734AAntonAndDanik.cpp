#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	int i,a=0,d=0;
	for(i=0;i<n;i++){
		if(str[i]=='A')
			a++;
		else
			d++;
	}
	if(a>d)
		cout<<"Anton"<<endl;
	else if(d>a)
		cout<<"Danik"<<endl;
	else
		cout<<"Friendship"<<endl;
}
