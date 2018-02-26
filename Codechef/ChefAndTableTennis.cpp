#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string word;
		cin>>word;
		int i;
		int one=0,zero=0;
		for(i=0;i<word.length();i++){
			if(word[i]=='1')
				one++;
			else
				zero++;
		}
		if(one>zero)
			cout<<"WIN"<<endl;
		else
			cout<<"LOSE"<<endl;
	}
}
