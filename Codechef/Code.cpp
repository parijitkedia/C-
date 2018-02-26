#include <iostream>
#include <cstring>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n,k,ans;
		cin>>n>>k>>ans;

		lli arr[n];
		lli i,j;
		for(i=1;i<=n;i++){
			cin>>arr[i];
		}
		string str;
		cin>>str;

		if(str[0]=='A'){
			for(i=1;i<=k;i++){
				for(j=1;j<=n;j++){
					ans=ans&arr[j];
				}
			}
			
			cout<<ans<<endl;
		}
		else if(str[0]=='X'){
			for(i=1;i<=k;i++){
				for(j=1;j<=n;j++){
					ans=ans^arr[j];
				}
			}
			
			cout<<ans<<endl;
		}
		else if(str[0]=='O'){
			for(i=1;i<=k;i++){
				for(j=1;j<=n;j++){
					ans=ans|arr[j];
				}
			}
			
			cout<<ans<<endl;
		}
	}
}
