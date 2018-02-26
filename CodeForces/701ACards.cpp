#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i,j,k,flag=0;
	int arr[n],val[n];
	int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		val[i]=0;
	}
	int a = sum/(n/2);
	int ctr=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a==arr[i]+arr[j] && val[i]==0 && val[j]==0){
				cout<<i+1<<" "<<j+1<<endl;
				val[i]=1;
				val[j]=1;
				ctr++;
				break;
			}
			if(ctr==n/2)
				break;
		}
		if(ctr==n/2)
			break;
	}
}
