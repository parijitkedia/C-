#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n,k,i;
	int ctr,flag;
	while(t--){
		ctr=0,flag=0;
		cin>>n>>k;
		int arr[n];

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		for(i=0;i<n;i++){
			if(arr[i]%2==0){
				ctr++;
				if(ctr==k){
					flag=1;
					break;
				}
			}else{
				if(k==0){
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else{
			cout<<"NO"<<endl;
		}
	}
}
