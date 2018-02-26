#include <iostream>
#include <cstring>

using namespace std;

int main(){

	string str,a,b;
	cin>>str;
	int i,flag=0;
	if(str[0]!='-'){
		cout<<str<<endl;
	}else{
		for(i=0;i<str.size()-1;i++){
			a=a+str[i];
		}
		for(i=0;i<str.size()-2;i++){
			b=b+str[i];
		}
		b=b+str[str.size()-1];

		for(i=1;i<str.size();i++){
			if(a[i]-'0' < b[i]-'0'){
				flag=1;
				break;
			}
		}

		if(flag==1){
			if(!a.compare("-0"))
				cout<<0<<endl;
			else
				cout<<a<<endl;
		}
		else{
			if(!b.compare("-0"))
				cout<<0<<endl;
			else
			cout<<b<<endl;
		}
	}
}
