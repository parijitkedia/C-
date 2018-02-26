#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<vector<int> > arr(4);
	int i,a;
	for(i=1;i<=n;i++){
		cin>>a;
		arr[a].push_back(i);
	}

	int minv=min(arr[1].size(),min(arr[2].size(),arr[3].size()));
	cout<<minv<<endl;
	if(minv!=0){
		for(i=0;i<minv;i++){
			cout<<arr[1][i]<<" "<<arr[2][i]<<" "<<arr[3][i]<<endl;
		}
	}
}
