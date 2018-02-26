#include <iostream>
#include <string>

using namespace std;

int main(){

	string word;
	cin>>word;
	int flag=0;

	int i;
	for(i=0;i<word.size();i++){
		if(word[i]=='H' || word[i]=='Q' || word[i]=='9'){
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
