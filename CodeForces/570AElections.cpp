#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	long long int arr[m][n];
	int i,j,k=0;

	int val[n];

	for(i=0;i<n;i++)
		val[i]=0;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	int maxv,pos;
	for(i=0;i<m;i++){
		maxv=-1,pos=0;
		for(j=0;j<n;j++){
			if(arr[i][j]>maxv){
				maxv=arr[i][j];
				pos=j;
			}
		}
		val[pos]++;
	}

	maxv=0;
	for(i=0;i<n;i++){
		if(val[i]>maxv){
			maxv=val[i];
			pos=i;
		}
	}
	cout<<pos+1<<endl;
}
