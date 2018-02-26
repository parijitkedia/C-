#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	int t;
	cin>>t;
	while(t--){
		cin>>word;
		int i;
		int count=0;
		for(i=0;i<word.length();i++){
			if(word[i]=='>')
				word[i]='<';
			else if(word[i]=='<')
				word[i]='>';
		}
		
		for(i=0;i<word.length()-1;i++){
			if(word[i]=='>' && word[i+1]=='<')
				count++;
		}
		cout<<count<<endl;
	}
}