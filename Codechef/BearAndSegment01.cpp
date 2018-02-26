#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	int flag=0;
	int pos=0,ctr;
	while(t--){
		flag=0,ctr=0;
		string str,res;
		cin>>str;
		pos=str.size();
		int i,j;
		for(i=0;i<str.size();i++){
			if(str[i]=='0'){
				ctr++;
			}
		}
		for(i=0;i<str.size();i++){
			int a=str.find('1');
			for(j=a;j<str.size();j++){
				if(str[j]=='1'){
					continue;
				}else{
					pos=j;
					break;
				}
			}
			for(j=pos;j<str.size();j++){
				if(str[j]=='1'){
					flag=1;
					break;
				}
			}
		}
		if(flag==1 || ctr==str.size())
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}
