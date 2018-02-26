#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count=2;

		int i;
		for(i=1;i<s.length();i++){
			if(s[i]<s[i-1]){
				count+=122-(int)s[i-1]+(int)s[i]-97+1;
				count++;
			}else if(s[i]>s[i-1]){
				count+=int(s[i])-(int)s[i-1];
				count++;
			}else{
				count++;
			}
		}
		if(count<=11*s.length())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
