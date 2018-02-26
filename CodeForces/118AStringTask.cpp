#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	string word;
	cin>>word;
	string ans="";
	int i;

	transform(word.begin(),word.end(),word.begin(),::tolower);

	for(i=0;i<word.size();i++){
		if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='y'){
			continue;
		}
		else
			ans=ans+"."+word[i];
	}

	cout<<ans<<endl;

}
