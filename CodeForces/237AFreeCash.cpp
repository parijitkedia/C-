#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int h,m;
	int arr[24][60];
	int i,j;
	for(i=0;i<24;i++){
		for(j=0;j<60;j++){
			arr[i][j]=0;
		}
	}
	int count=0;
	for(i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]++;
		if(arr[a][b]>count)
			count=arr[a][b];
	}

	cout<<count<<endl;
}
