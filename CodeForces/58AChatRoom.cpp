#include <iostream>
#include <string>

using namespace std;

int main(){

	string word;
	string hello="hello";
	cin>>word;

	int i,j=0;

	for(i=0;i<word.size();i++){
		if(word[i]==hello[j]){
			j++;
		}
		if(j==5)
			break;
	}
	if(j==5)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

    return 0;
}
