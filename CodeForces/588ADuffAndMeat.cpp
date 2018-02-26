#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n][2];
	int i,j;
	int a=100,ans=0;
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		a = min(arr[i][1],a);
		ans+=a*arr[i][0];
	}
	cout<<ans<<endl;
}
