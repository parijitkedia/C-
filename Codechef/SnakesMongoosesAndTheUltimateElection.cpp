#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	int s=0,m=0;
	int i;
	while(t--){
		s=0,m=0;
		string str;
		cin>>str;
		int arr[str.size()];

		for(i=0;i<str.size();i++){
			arr[i]=0;
		}

		for(i=0;i<str.size();i++){
			if(str[i]=='m')
				m++;
			else
				s++;
		}

		for(i=1;i<str.size();i++){
			if((str[i]=='m' && str[i-1]=='s' && arr[i-1]==0) || (str[i]=='s' && str[i-1]=='m' && arr[i-1]==0)){
				s--;
				arr[i]=1;
			}
		}
		if(m==s)
			cout<<"tie"<<endl;
		else if(m<s)
			cout<<"snakes"<<endl;
		else
			cout<<"mongooses"<<endl;
	}
}
