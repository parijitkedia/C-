#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;

		int i;
		int count=0;

		int prevdot=1,currdot=1;
		for(i=0;i<s.length();i++){
			if(s[i]=='.')
				currdot++;
			else if(s[i]=='#'){
				if(currdot>prevdot){
					count++;
					prevdot=currdot;
				}
				currdot=1;
			}
		}
		cout<<count<<endl;
	}
}
