#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;
		lli arr[n],i,j,ans;

		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		lli c2=0,oth=0;
		for(i=0;i<n;i++){
			if(arr[i]==2){
				c2++;
			}else if(arr[i]>2){
				oth++;
			}
		}
		ans = oth*(oth-1)/2 + oth*c2;

		cout<<ans<<endl;
	}
}

