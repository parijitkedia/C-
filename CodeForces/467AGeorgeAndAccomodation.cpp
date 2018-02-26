#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;
	int arr[n][2];
	int count=0;
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		if(arr[i][1]-arr[i][0]>=2)
			count++;
	}

	cout<<count<<endl;

}
