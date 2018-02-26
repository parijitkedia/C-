#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i,j,num;
	int sum=0;
	int val[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		val[i]=sum;
	}

	int m;
	cin>>m;

	for(i=0;i<m;i++){
		cin>>num;
		for(j=0;j<n;j++){
			sum+=arr[j];
			if(num<=sum){
				cout<<j+1<<endl;
				break;
			}
		}
		sum=0;
	}
}
