#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	string word;
	cin>>word;
	int i;
	int zero=0,ones=0;
	for(i=0;i<n;i++){
		if(word[i]=='1')
			ones++;
		else
			zero++;
	}
	if(ones<=zero){
		cout<<n-2*ones<<endl;
	}else{
		cout<<n-2*zero<<endl;
	}
}