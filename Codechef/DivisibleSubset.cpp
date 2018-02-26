#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int arr[n];
		int i,j,k;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		int sum,ctr,flag=0;
		for(i=0;i<n;i++){
			sum=0;
			ctr=0;
			for(j=i;j<n;j++){
				sum+=arr[j];
				ctr++;
				if(sum%n==0){
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1){
			cout<<j-i+1<<endl;
			for(k=i;k<=j;k++){
				cout<<k+1<<" ";
			}
			cout<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}
