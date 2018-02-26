#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int k;
	cin>>k;
	int sum=0,count=0;
	int arr[12];
	int i;
	int sum1=0;
	for(i=0;i<12;i++){
		cin>>arr[i];
		sum1=sum1+arr[i];
	}

	sort(arr,arr+12);
	if(k==0)
		cout<<0<<endl;
	else if(sum1<k)
		cout<<-1<<endl;
	else{
		for(i=11;i>=0;i--){
			sum=sum+arr[i];
			count++;
			if(sum>=k)
				break;
		}
		cout<<count<<endl;
	}
}
