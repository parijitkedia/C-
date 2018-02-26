#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){

	set<char> arr;
	string word;
	getline(cin,word);

	int i;

	for(i=0;i<word.length();i++){
		if(isalpha(word[i]))
			arr.insert(word[i]);
	}
	cout<<arr.size()<<endl;
}
