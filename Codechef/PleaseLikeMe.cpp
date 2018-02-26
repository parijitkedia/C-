#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		lli l,d,s,c;
		cin>>l>>d>>s>>c;
		int flag=0;
		lli i,sum=s;
		for(i=1;i<=d;i++){
			if(sum>=l){
				flag=1;
				break;
			}else{
				sum+=sum + sum*c;
			}
		}
		if(flag==1)
			cout<<"ALIVE AND KICKING"<<endl;
		else
			cout<<"DEAD AND ROTTING"<<endl;

	}
}
