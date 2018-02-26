#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int n;
	cin>>n;
	int i,ans;

	int arr[n];
	int count[5]={0};

	for(i=0;i<n;i++){
		cin>>arr[i];
		count[arr[i]]++;
	}
	/*for(i=1;i<=4;i++){
		cout<<count[i]<<" ";
	}*/

	int c = max(count[1]-count[3],0);
	

	ans = count[4]+count[3]+(c+2*count[2]+3)/4;
	
	cout<<ans<<endl;
}
