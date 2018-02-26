#include <iostream>

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

		int inv=0,linv=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(arr[i]>arr[j]){
					inv++;
				}
			}
		}

		for(i=0;i<n-1;i++){
			if(arr[i]>arr[i+1]){
				linv++;
			}
		}
		if(inv==linv){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}