#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	cin>>str;
	int i;
	int ctr=0;
	int l=str.size();
	for(i=0;i<l/2;i++){
		if(str[i]==str[l-i-1]){
			continue;
		}else{
			ctr++;
		}
	}
	if( (ctr==0 && l%2!=0) || (ctr==1)){
		cout<<"YES"<<endl;
	}else
		cout<<"NO"<<endl;
}
