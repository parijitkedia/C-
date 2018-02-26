#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		int arr[n];
		int i;
		for(i=0;i<n;i++)
			cin>>arr[i];

		if(n==1 && s=="Dee" && arr[0]%2==0)
			cout<<"Dee"<<endl;
		else
			cout<<"Dum"<<endl;
	}
}