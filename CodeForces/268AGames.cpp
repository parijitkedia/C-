#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n][2];
	int i,j;
	int count=0;
	for(i=0;i<n;i++){
		for(j=0;j<2;j++)
			cin>>arr[i][j];
	}	

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][0]==arr[j][1])
				count++;
		}
	}
	cout<<count<<endl;
}