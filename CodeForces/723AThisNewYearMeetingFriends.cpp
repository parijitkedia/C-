#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int arr[3];
	int i;
	for(i=0;i<3;i++)
		cin>>arr[i];

	sort(arr,arr+3);

	cout<<arr[2]-arr[0]<<endl;

}
