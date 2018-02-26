#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int count=0;

	int arr[n];

	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=0;i<n;i++){
		if(arr[i]<=5-k){
			count++;
		}
	}
	cout<<count/3<<endl;
}
