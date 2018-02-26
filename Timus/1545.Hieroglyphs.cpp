#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;

	vector<string> str;
	string s;
	for(i=0;i<n;i++){
		cin>>s;
		str.push_back(s);
	}
	char a;
	cin>>a;
	for(i=0;i<n;i++){
		if(str[i][0]==a){
			cout<<str[i]<<endl;
		}
	}
}
