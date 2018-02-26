#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	long long int n,d;
	cin>>n>>d;
	long long int arr[n];
	int i,j;
	int count=0,ans=0;

	for(i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);

	for(j=0;j<n-1;){
		if(abs(arr[j]-arr[j+1])<=d){
			count++;
			j+=2;
		}else{
			j++;
		}
	}
	if(count>ans)
		ans=count;

	cout<<ans<<endl;
}
