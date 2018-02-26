#include <iostream>

using namespace std;

int main(){
	long long int n,x;
	cin>>n>>x;
	long long int i,j;
	int count=0;
	for(i=1;i<=n;i++){
		if(x%i==0 && x/i<=n)
			count++;
	}
	cout<<count<<endl;
}
