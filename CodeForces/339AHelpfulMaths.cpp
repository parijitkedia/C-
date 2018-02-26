#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	string word;
	cin>>word;
	int plus=0;
	string newword="";
	int i;

	sort(word.begin(),word.end());

	for(i=0;i<word.size();i++){
		if(word[i]=='+')
			plus++;
        else
            break;
	}

	for(i=plus;i<word.size();i++){
		newword=newword+word[i]+"+";
	}
	for(i=0;i<newword.size()-1;i++)
        cout<<newword[i];
    cout<<endl;
}
