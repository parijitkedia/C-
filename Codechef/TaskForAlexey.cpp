#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int lcm(long long int a , long long int b){
	long long int maxv = max(a,b);
	do{
		if(maxv%a==0 && maxv%b==0){
			return maxv;
		}else{
			++maxv;
		}
	}while(true);
}

int main(){
	int t;
	cin>>t;
	int n;
	int i,j;
	while(t--){
		long long int ans=999999999;
		cin>>n;
		long long int arr[n];
		long long int res[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				ans = min(ans,lcm(arr[i],arr[j]));
			}
		}
		cout<<ans<<endl;
	}
}
