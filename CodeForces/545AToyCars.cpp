#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n][n];
	int i,j;

	vector<int> val;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	int ctr=0;
	for(i=0;i<n;i++){
		ctr=0;
		for(j=0;j<n;j++){
			if(arr[i][j]==0 || arr[i][j]==2){
				ctr++;
			}
		}
		if(ctr==n-1){
			val.push_back(i+1);
		}
	}
	cout<<val.size()<<endl;
	for(i=0;i<val.size();i++){
		cout<<val[i]<<" ";
	}
	cout<<endl;
}
