#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];

	int i;
	int ctr=k,flag=0,sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
   	if(k<=8*n && sum>=k){
   		
   	}else
   		cout<<-1<<endl;
}
