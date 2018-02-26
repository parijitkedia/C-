#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	int len=0,i;

	while(t--){
		string word;

		cin>>word;
		if(word.size()>10){	
			for(i=0;i<word.size();i++){
				len++;
			}
			cout<<word[0]<<len-2<<word[word.size()-1]<<endl;

		}else{
			cout<<word<<endl;
		}
		len=0;

	}
}