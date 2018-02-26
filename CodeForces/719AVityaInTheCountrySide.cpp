#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;

	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	if(arr[n-1]==15)
		cout<<"DOWN"<<endl;
	else if(arr[n-1]==0)
		cout<<"UP"<<endl;
	else if(n==1)
		cout<<-1<<endl;
	else if(arr[n-1]>arr[n-2])
		cout<<"UP"<<endl;
	else
		cout<<"DOWN"<<endl;
}
