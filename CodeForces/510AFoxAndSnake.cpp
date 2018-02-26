#include <iostream>

using namespace std;

int main(){
	int n,m;

	cin>>n>>m;

	int arr[n][m];
	int i,j;
	for(i=0;i<n;i++){
		if(i%4==0 || i%4==2){
			for(j=0;j<m;j++)
				cout<<"#";
            cout<<endl;
		}
		else if(i%4==1){
			for(j=0;j<m-1;j++)
				cout<<".";
			cout<<"#";
			cout<<endl;
		}

		else if(i%4==3){
			cout<<"#";
			for(j=0;j<m-1;j++)
				cout<<".";
            cout<<endl;
		}
	}
}
