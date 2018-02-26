#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string word;
		cin>>word;
		int pos=word.find("101");
		int pos1=word.find("010");
		if(pos!=-1 || pos1!=-1)
			cout<<"Good"<<endl;
		else
			cout<<"Bad"<<endl;
	}
}
