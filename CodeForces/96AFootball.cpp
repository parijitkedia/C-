#include <iostream>
#include <string>

using namespace std;

int main(){

	string word;
	cin>>word;
	int count=0;
	int i,j;

	for(i=0;i<word.size();i++){
		char c=word[i];
		for(j=i;j<word.size();j++){
			if(c==word[j]){
				count++;
			}
			else
                break;
		}
		if(count>=7)
			break;
        count=0;
	}

	if(count>=7)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}
