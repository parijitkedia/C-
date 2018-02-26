#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string word;
		cin>>word;
		int i,zero=0,one=0;
		for(i=0;i<word.length();i++){
			if(word[i]=='1')
				one++;
			else
				zero++;
		}
		if(one==1 || zero==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		zero=0;
		one=0;
	}
}
