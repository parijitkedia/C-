#include <iostream>
#include <cstring>

using namespace std;

int main(){
	long int n,i,sum=0;
	cin>>n;

	string str;

	for(i=0;i<n;i++){
		cin>>str;
		if(str[0]=='T')
			sum+=4;
		else if(str[0]=='C')
			sum+=6;
		else if(str[0]=='I')
			sum+=20;
		else if(str[0]=='O')
			sum+=8;
		else
			sum+=12;
	}
	cout<<sum<<endl;
}