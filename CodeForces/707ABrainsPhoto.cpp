#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	char arr[n][m];
	int i,j;
	int flag=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(arr[i][j]=='B' || arr[i][j]=='G' || arr[i][j]=='W'){
				continue;
			}
			else{
				flag=1;
				break;
			}
		}
	}

	if(flag==0)
		cout<<"#Black&White"<<endl;
	else
		cout<<"#Color"<<endl;
}