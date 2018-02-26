#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int k;
	cin>>k;
	int arr[k];

	int i,sum=0;
	for(i=0;i<k;i++){
		cin>>arr[i];
	}

	sort(arr,arr+k);

	for(i=0;i<ceil(k/2.0);i++){
		sum+=ceil(arr[i]/2.0);
	}
	cout<<sum<<endl;
}
