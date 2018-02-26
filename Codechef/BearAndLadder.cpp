#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int q;
	cin>>q;
	long long int a,b,i,j;
	while(q--){
		cin>>a>>b;
		if(a%2==1){
			i=(a-1)/2;
			j=b;
		}else{
			i=(b-1)/2;
			j=a;
		}

		if((2*i)+2==j || (a%2==0 && b%2==0 && abs(a-b)==2) || (a%2==1 && b%2==1 && abs(a-b)==2) ) 
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}