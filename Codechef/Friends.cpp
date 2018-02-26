#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	char arr[n][10];
	int i,j;
	int ctr=0;
	int k=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//cout<<arr[i][j]<<" "<<i<<" "<<j<<endl;
			if(arr[i][j]=='0' && i!=j){
				ctr++;
			}
		}
	}
	cout<<ctr<<endl;
}
