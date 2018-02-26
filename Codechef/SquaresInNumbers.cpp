#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lli;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;

		lli i,j,prod=1;
		int flag=0;
		for(i=0;i<n;i++){
			lli a;
			cin>>a;
			prod*=a;

			for(j=2;j*j<prod;j++){
				if(prod%(j*j)==0){
					cout<<j<<endl;
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}


	}
}
