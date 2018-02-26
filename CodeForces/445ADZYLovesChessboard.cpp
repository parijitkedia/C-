#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int i,j;
	char str[n][m];

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>str[i][j];
		}
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(str[i][j]=='.'){
				if( (i%2!=0 && j%2!=0) || (i%2==0 && j%2==0) ){
					str[i][j]='B';
				}else{
					str[i][j]='W';
				}
			}
		}
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<str[i][j];
		}
		cout<<endl;
	}
}
