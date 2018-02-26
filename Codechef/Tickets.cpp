#include <iostream>
#include <string>

using namespace std;

bool check(string str){
	if(str[0]==str[1])
		return false;
	int i;
	for(i=0;i+2<str.length();i++)
		if(str[i]!=str[i+2])
			return false;
	return true;
}

int main(){
	int t;
	cin>>t;
	int i;
	int flag=0;
	while(t--){
		string word;
		cin>>word;
		bool ans = check(word);
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
