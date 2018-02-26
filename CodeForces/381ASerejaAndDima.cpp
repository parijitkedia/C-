#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];
	int i,j=n-1,k=0;

	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int s=0,d=0;
	for(i=0;i<n/2;i++){
		if(k<=j){
			if(i%2==0){
				if(arr[k]>arr[j]){
					s+=arr[k];
					k++;
				}else{
					s+=arr[j];
					j--;
				}
			}else{
				if(arr[k]>arr[j]){
					d+=arr[k];
					k++;
				}else{
					d+=arr[j];
					j--;
				}
			}
		}
	}
	cout<<s<<" "<<d<<endl;
}