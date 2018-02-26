#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int i,j;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		int ans=0,maxvalue;
		for(i=0;i<n;i++){
			int a=arr[i];
			maxvalue=0;
			for(j=i+1;j<n;j++){
				maxvalue=max(maxvalue,arr[j]);
			}
			//cout<<maxvalue<<endl;
			if(maxvalue>a){
				int b=maxvalue-a;
				if(b>ans){
					ans=b;
				}
			}
		}
		if(ans==0)
			cout<<"UNFIT"<<endl;
		else
			cout<<ans<<endl;
	}
}
