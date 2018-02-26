#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	string ans;
	int i;
	int u=0,l=0;
	cin>>word;

	for(i=0;i<word.length();i++){
		if(isupper(word[i]))
			u++;
		else
			l++;
	}

	if(u>l){
		for(i=0;i<word.length();i++){
			word[i]=toupper(word[i]);
		}
	}else{
		for(i=0;i<word.length();i++){
			word[i]=tolower(word[i]);
		}
	}
	cout<<word<<endl;
}
