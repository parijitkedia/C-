#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;

	int arr[n][n];
    int i,j;
	for(i=0;i<n;i++){
		arr[i][0]=1;
		arr[0][i]=1;
	}

	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			arr[i][j]=arr[i-1][j]+arr[i][j-1];
		}
	}

	cout<<arr[n-1][n-1]<<endl;
}
