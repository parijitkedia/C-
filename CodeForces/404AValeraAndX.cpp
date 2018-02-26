#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;

	char str[n][n];
	int i,j;
	for(i=0;i<n;i++){
		cin>>str[i];
	}

	char a = str[0][0];
	char b = str[0][1];

	int ctr=0,ctr1=0;
	for(i=0;i<n;i++){
		if(str[i][i]==str[i][n-i-1] && str[i][i]==a){
			ctr++;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(str[i][j]==b){
		//		cout<<i<<" "<<j<<endl;
				ctr1++;
			}
		}
	}
	//cout<<ctr1<<endl;
	if(ctr==n && ctr1==((n-1)*(n-1)))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
