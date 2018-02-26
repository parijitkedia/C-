#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	char arr[n][5];
	int i,j;
	int a=0,b=3;
	int flag=0;

	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		if(arr[i][a]=='O' && arr[i][a+1]=='O'){
			arr[i][a]='+';
			arr[i][a+1]='+';
			flag=1;
			break;
		}
		if(arr[i][b]=='O' && arr[i][b+1]=='O'){
			arr[i][b]='+';
			arr[i][b+1]='+';
			flag=1;
			break;
		}
	}

	if(flag==1){
		cout<<"YES"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<5;j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}else{
		cout<<"NO"<<endl;
	}
}
