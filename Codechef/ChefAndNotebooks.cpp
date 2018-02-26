#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int x,y,k,n;
		cin>>x>>y>>k>>n;

		int arr[n][2];
		int i,j;
		int flag=0;

		for(i=0;i<n;i++){
			for(j=0;j<2;j++){
				cin>>arr[i][j];
			}
		}

		int left = x-y;

		for(i=0;i<n;i++){
			if(arr[i][0]>=left && arr[i][1]<=k){
				cout<<"LuckyChef"<<endl;
				flag=0;
				break;
			}else{
				flag=1;
			}
		}
		if(flag==1)
			cout<<"UnluckyChef"<<endl;
	}
}