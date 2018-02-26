#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	int n,d;
	cin>>n>>d;
	int i,j,a,ctr=0,ans=0,flag=0;
	string str;
	for(i=0;i<d;i++){
		cin>>str;
		a=0,flag=0;
		for(j=0;j<n;j++){
			if(str[j]-'0'==0){
				flag=1;
				break;
			}else{
				a++;
			}
		}
		if(flag==1){
			ctr++;
            ans=max(ans,ctr);
		}
		if(a==n){
			ans=max(ans,ctr);
			ctr=0;
		}
	}
	cout<<ans<<endl;
}
