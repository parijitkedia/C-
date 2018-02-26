#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a=n%8;
		if(a==0)
			a=8;
		if(a==1){
			cout<<n+3<<"LB"<<endl;
		} 
		if(a==2){
			cout<<n+3<<"MB"<<endl;
		} 
		if(a==3){
			cout<<n+3<<"UB"<<endl;
		} 
		if(a==4){
			cout<<n-3<<"LB"<<endl;
		} 
		if(a==5){
			cout<<n-3<<"MB"<<endl;
		} 
		if(a==6){
			cout<<n-3<<"UB"<<endl;
		} 
		if(a==7){
			cout<<n+1<<"SU"<<endl;
		} 
		if(a==8){
			cout<<n-1<<"SL"<<endl;
		} 
	}
}