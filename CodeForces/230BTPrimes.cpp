#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;

	long long int a;
	long long int i,j;
	int ctr=0;
	for(i=0;i<n;i++){
		cin>>a;
		for(j=1;j<=sqrt(a);j++){
			if(a%j==0 && j*j!=a){
				ctr+=2;
			}
			if(a%j==0 && j*j==a)
				ctr++;
			if(ctr>3)
				break;
		}
		if(ctr==3)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		ctr=0;
	}
}
