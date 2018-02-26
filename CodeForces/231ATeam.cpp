#include <iostream>

using namespace std;

int main(){

	int n;
	int i,j;
	int count=0,ans=0;
	cin>>n;

	int arr[n][3];

	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			if(arr[i][j]==1)
				count++;
		}
		if(count>=2)
			ans++;
		count=0;
	}

	cout<<ans<<endl;
}
