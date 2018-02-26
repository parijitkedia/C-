#include <iostream>

using namespace std;

int main(){

	int n;

	cin>>n;
	int arr[n][2];
	int max=0;
	int i,j;
	int ans=0;

	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			if(j==0)
				ans-=arr[i][j];
			if(j==1){
				ans+=arr[i][j];
			}
			if(ans>max)
				max=ans;
		}
	}

	cout<<max<<endl;

}
