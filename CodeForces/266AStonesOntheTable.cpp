#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;

	string word;
	cin>>word;

	int i;
	int count=0;

	for(i=0;i<word.size()-1;i++){
		if(word[i]==word[i+1]){
			count++;
		}
	}

	cout<<count<<endl;
}