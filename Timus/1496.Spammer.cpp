#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int main(){

	int n,i;
	string s;
	map<string,int>M;

	cin>>n;
	vector<string> str;

	for(i=0;i<n;++i){
		cin>>s;
		++M[s];
		if(M[s]>1){
			str.push_back(s);
			M[s]=-1e9;
		}
	}
	for(i=0;i<str.size();i++){
		cout<<str[i]<<endl;
	}
}
