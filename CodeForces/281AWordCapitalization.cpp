#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(){

	string word;
	int i,a;
	string ans;
	cin>>word;

	if((int)word[0]>=97 && (int)word[0]<=123){
		 a=(int)word[0]-32;
		 word[0]=a;
	}

    cout<<word<<endl;
}
