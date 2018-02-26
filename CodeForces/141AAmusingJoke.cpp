#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string word1;
	string word2;
	string word3;

	cin>>word1;
	cin>>word2;
	cin>>word3;

	word1=word1+word2;
	sort(word1.begin(),word1.end());
	sort(word3.begin(),word3.end());

	if(word1==word3)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


}
