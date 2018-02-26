#include <iostream>

using namespace std;

int main(){
	int t;
	int flag=0;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int i;
		flag=0;
		for(i=1;i<str.size();i++){
			//cout<<(int)str[i]<<endl;
			if((int)str[i] - (int)str[i-1]>=0)
				continue;
			else{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
}
