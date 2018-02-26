#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i,j;
	int val;
	int arr[3]={0};
	for(i=0;i<3;i++){
		for(j=0;j<n-i;j++){
			cin>>val;
			arr[i]+=val;
		}
	}
	cout<<arr[0]-arr[1]<<endl;
	cout<<arr[1]-arr[2]<<endl;
}
