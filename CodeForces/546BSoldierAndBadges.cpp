#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;
	int ctr=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr,arr+n);

	for(i=1;i<n;i++){
		if(arr[i]==arr[i-1]){
			//cout<<i<<" ";
			arr[i]+=1;
			ctr++;
			//cout<<"first "<<arr[i]<<" "<<arr[i+1]<<endl;
		}
	}
	cout<<ctr<<endl;

}
