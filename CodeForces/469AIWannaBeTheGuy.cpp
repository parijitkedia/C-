#include <iostream>

using namespace std;

int main(){
	int n;
	int p;
	int q;

	cin>>n;
	cin>>p;

	int arr[n];
	int arr1[p];

	int count=0;
	int i;

	for(i=0;i<n;i++){
		arr[i]=0;
	}

	for(i=0;i<p;i++){
		cin>>arr1[i];
		arr[arr1[i]-1]=1;
	}

	cin>>q;
	int arr2[q];

	for(i=0;i<q;i++){
		cin>>arr2[i];
		arr[arr2[i]-1]=1;
	}

	for(i=0;i<n;i++){
		if(arr[i]==1)
			count++;
	}

	if(count==n)
		cout<<"I become the guy."<<endl;
	else
		cout<<"Oh, my keyboard!"<<endl;

}
