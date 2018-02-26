#include <iostream>

using namespace std;

int main(){
	int n,m;

	cin>>n>>m;
	int sum=0;
	while(n>=m){
		sum+=m;
		n=n-m+1;
	}
	sum=sum+n;
	cout<<sum<<endl;
}
