#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c,q;
		cin>>n>>c>>q;
		int arr[q][2];
		int i,j;
		for(i=0;i<q;i++){
			for(j=0;j<2;j++){
				cin>>arr[i][j];
			}
		}
		for(i=0;i<q;i++){
			if(arr[i][0]<=c && c<=arr[i][1])
				c=arr[i][0]+arr[i][1]-c;
		}
		cout<<c<<endl;
	}
}