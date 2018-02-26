#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli arr[3];
		lli i;
		for(i=0;i<3;i++){
			cin>>arr[i];
		}

		sort(arr,arr+3);
		long long int m = 1000000007;

		long long int ans;
		ans = (((arr[0]%m)*((arr[1]-1)%m))%m * ((arr[2]-2)%m))%m;
		cout<<ans<<endl;
	}
}
