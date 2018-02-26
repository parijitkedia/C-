#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i,j;
	string str;
	int cost=200,pos=2;
	for(i=0;i<n;i++){
		cin>>str;
		for(j=0;j<str.size();j++){
			if(str[j]=='+'){
				cost+=100;
				pos++;
				break;
			}
		}
		pos++;
		cost+=100;
	}
	if(pos==13)
		cout<<cost+100<<endl;
	else
		cout<<cost<<endl;
}
