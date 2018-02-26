#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n,i,j;
	int ctr,k;
	while(t--){
		ctr=0,k=0;
		cin>>n;
		long long int arr[n];
		long long int res[n*(n-1)/2];

		//cout<<n*(n-1)/2<<endl;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				res[k]=arr[i]*arr[j];
				k++;
			}
		}

		//for(i=0;i<k;i++)
		//	cout<<res[i]<<endl;

		for(i=0;i<n;i++){
			for(j=0;j<k;j++){
				if(arr[i]==res[j]){
					ctr++;
				}
			}
		}
		if(ctr==k)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
