#include <iostream>

using namespace std;

int main(){

	string word;
	cin>>word;
	int flag=0,count=0;

	int i;
	for(i=0;i<word.size();i++){
		if(isupper(word[i]))
			flag++;
	}

	if(word.length()==1){
		if(isupper(word[0]))
			word[0]=tolower(word[0]);
		else
			word[0]=toupper(word[0]);
	}
	else if(flag==word.length()){
		for(i=0;i<word.length();i++){
			word[i]=tolower(word[i]);
		}
	}else{
		for(i=1;i<word.length();i++){
			if(isupper(word[i]))
				count++;
		}
		if(count==word.length()-1){
			for(i=1;i<word.length();i++){
				word[i]=tolower(word[i]);
			}
			word[0]=toupper(word[0]);
		}
	}
	cout<<word<<endl;
}
