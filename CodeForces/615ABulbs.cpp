#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int arr[m];
	int i,j,flag=0;

	for(i=1;i<=m;i++){
		arr[i]=0;
	}

	for(i=1;i<=n;i++){
		int x;
		cin>>x;
		for(j=1;j<=x;j++){
			int a;
			cin>>a;
			arr[a]++;
		}
	}

	for(i=1;i<=m;i++){
		if(arr[i]!=0){
			flag=1;
		}else{
			flag=0;
			break;
		}
	}
	if(flag==0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}
