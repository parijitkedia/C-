#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	int i,j;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	int unus=0,left=0;
	for(i=0;i<n;i++){
		int ans=arr[i]-k;
		if(ans<0){
			left+=-ans;
		}else{
			unus+=ans;
		}
	}
	cout<<unus<<" "<<left<<endl;
}