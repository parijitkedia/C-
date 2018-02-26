#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];
	int i;
	int count=0,ans=0;
	for(i=0;i<n;i++)
		cin>>arr[i];

	for(i=0;i<n;i++){
		count=count+arr[i];
		if(count<0){
			ans++;
			count=0;
		}
	}
	cout<<ans<<endl;
}
