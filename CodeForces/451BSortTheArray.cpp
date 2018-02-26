#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	long long int arr[n];

	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[j]>arr[j+1]){
				first = j;
				last = j+1;
			}else{

			}
		}
	}
}