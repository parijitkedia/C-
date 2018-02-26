#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string str,word;
		cin>>str;
		cin>>word;
		int count=0;
		int i,j;
		for(i=0;i<word.length();i++){
			for(j=0;j<str.length();j++){
				if(word[i]==str[j]){
					count++;
					break;
				}
			}
		}
		cout<<count<<endl;
	}
}
