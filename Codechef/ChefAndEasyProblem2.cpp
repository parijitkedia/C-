#include <iostream>

using namespace std;

int prime(int a){

	int i,j;
	int ctr=0;
	for(i=2;i<=a;i++){
		if(a%i==0){
			ctr++;
		}
	}
	if(ctr==2)
		return 1;
	else
		return 0;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int val[n];
		int i,j;
		for(i=0;i<n;i++){
			cin>>arr[i];
			val[i]=0;
		}

		for(i=2;i<5;i++){
			int a = prime(i);
			if(a==1){
				for(j=0;j<n;j++){
					if(arr[j]%i==0 && val[j]==0){
						val[j]=arr[j]/i;
					}
				}
			}else{
				continue;
			}
		}

		for(i=0;i<n;i++){
			cout<<val[i]<<" ";
		}
	}
}
