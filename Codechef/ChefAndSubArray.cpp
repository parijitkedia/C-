#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int n;
	cin>>n;
	long long int arr[n];
	long long int i;
	long long int len=0,ctr=0,ans=1;
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=0){
			ctr++;
			len=max(len,ctr);
		}else{
			ctr=0;
		}
	}
	cout<<len<<endl;
}
