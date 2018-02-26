#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;

	int i,ctr=0;
	for(i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			ctr++;
		}
	}
	if(ctr%2!=0){
		cout<<"impossible"<<endl;
	}else{
		int k=ctr/2;
		int a=0;
		for(i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				if(s2[i]=='0')
					s2[i]='1';
				else
					s2[i]='0';
				a++;
			}
			if(a==k)
				break;
		}
		cout<<s2<<endl;
	}
}