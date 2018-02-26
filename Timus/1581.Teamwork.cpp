#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];
	int res[1024];
	int i;

	for(i=0;i<1024;i++)
		res[i]=0;

	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr,arr+n);

	for(i=0;i<n;i++){
		res[arr[i]]++;
	}

	for(i=0;i<1024;i++){
		if(res[i]!=0){
			cout<<res[i]<<" "<<i<<" ";
		}
	}
	cout<<endl;
}
