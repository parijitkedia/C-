#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	string s;
	int i;
	int u=0,d=0;
	int useg=0,dseg=0;
	while(t--){
		u=0,d=0,useg=0,dseg=0;
		cin>>s;
		for(i=0;i<s.size();i++){
			if(s[i]=='U')
				u++;
			else
				d++;
		}
		for(i=0;i<s.size();i++){
			if(s[i]=='U' && s[i+1]!='U')
				useg++;
			if(s[i]=='D' && s[i+1]!='D')
				dseg++;
		}
		if(useg==dseg){
			if(u<d)
				cout<<useg<<endl;
			else
				cout<<dseg<<endl;
		}else{
			if(useg<dseg)
				cout<<useg<<endl;
			else
				cout<<dseg<<endl;
		}
	}
}