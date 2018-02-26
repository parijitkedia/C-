#include <iostream>
#include <cstring>

typedef long long int lli;

using namespace std;

int main(){
	string str;
	cin>>str;
	str="00"+str;

	lli i,j,k;
	lli ans,flag=0;
	for(i=0;i<str.size();i++){
		for(j=i+1;j<str.size();j++){
			for(k=j+1;k<str.size();k++){
				ans = (str[i]-'0')*100 + (str[j]-'0')*10 + (str[k]-'0');
				if(ans%8==0){
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			break;
	}
	if(flag==1){
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}