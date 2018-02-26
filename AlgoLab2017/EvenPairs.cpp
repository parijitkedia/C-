#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int i;
		int arr[n];

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		int e=0,o=0,ans=0;
		for(i=0;i<n;i++){
			ans+=arr[i];
			if(ans%2==0)
				e++;
			else
				o++;
		}

		cout<<e*(e-1)/2 + o*(o-1)/2 + e<<endl;
	}
}
