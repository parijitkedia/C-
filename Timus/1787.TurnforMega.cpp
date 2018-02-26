#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int k,n;
	cin>>k>>n;
	int i,a,rem=0,ans;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=0;i<n;i++){
		rem=arr[i]-k;
		if(rem>0){
			arr[i+1]+=rem;
		}
	}
	ans = arr[n-1]-k;
	if(ans<0)
        ans=0;
	cout<<ans<<endl;
}
