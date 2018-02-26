#include <iostream>
#include <cstring>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string str,str1,str2;
		cin>>str;
		lli i;
		lli ctr=0,ctr1=0;

		int l=str.size();

		for(i=0;i<l;i++){
			if(i%2==0){
				str1+='+';
				str2+='-';
			}else{
				str1+='-';
				str2+='+';
			}
		}
		
		for(i=0;i<l;i++){
			if(str1[i]!=str[i])
				ctr++;
			if(str2[i]!=str[i])
				ctr1++;
		}
		
		cout<<min(ctr,ctr1)<<endl;
	}
}