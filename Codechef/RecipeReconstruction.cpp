#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len=s.length();
		int i,countques=0;
		int ans=1;
		for(i=0;i<len;i++){
			if(i>len-i-1)
				break;
			if(s[i]=='?' && s[len-i-1]=='?')
				ans=(ans*26)%10000009;
			if(s[i]!='?' && s[len-i-1]!='?' && s[i]!=s[len-i-1]){
				ans=0;
				break;
			}
		}
		cout<<ans<<endl;
	}
}
