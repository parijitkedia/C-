#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long arr[100000];
	int n;
	int i,val;
	cin>>n;

    for(i=0;i<100000;i++)
        arr[i]=0;

	for(i=0;i<n;i++){
		cin>>val;
		arr[val]++;
	}
	for(i=2;i<=100000;i++){
		arr[i]=max(arr[i-1],arr[i]+arr[i-2]);
	}
	cout<<arr[100000]<<endl;
}
