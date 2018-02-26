#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int arr[t];
	int i;
	for(i=0;i<t;i++)
		cin>>arr[i];

	for(i=0;i<t;i++){
		float ans = 360/(float)(180-arr[i]);
		if(ans-(int)ans==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
