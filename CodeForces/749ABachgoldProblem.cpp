#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;

	int m=n/2;
	cout<<m<<endl;
	for(i=0;i<m-1;i++){
		cout<<2<<" ";
	}
	if(n%2==1)
		cout<<3<<" ";
	else
		cout<<2<<" ";
	cout<<endl;
}
