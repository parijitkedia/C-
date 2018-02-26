#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	string str;
	cin>>str;

	int i,j;
	int pos,k=0,maxv=0;
	for(i=0;i<str.size();i++){
		int pos=strchr("A",k);
		cout<<pos<<endl;
		k=pos;
		maxv=max(maxv,pos);
	}
	cout<<maxv<<endl;
}
