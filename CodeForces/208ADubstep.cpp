#include <iostream>
#include <string>

using namespace std;

int main(){

	string word;
	cin>>word;
	int i;

	i=word.find("WUB");
	while(i!=-1){
		word.replace(i,3," ");
		i=word.find("WUB");
	}

	cout<<word<<endl;
}
