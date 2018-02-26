#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	string word1,word2;
	cin>>word1;
	cin>>word2;
	int i;
	int count=0;

	transform(word1.begin(),word1.end(),word1.begin(),::tolower);
	transform(word2.begin(),word2.end(),word2.begin(),::tolower);

	int len;
	len=word1.size();

	
	if(word1.compare(word2)<0)
		cout<<-1<<endl;
	else if(word1.compare(word2)>0)
		cout<<1<<endl;
	else
		cout<<0<<endl;


}
