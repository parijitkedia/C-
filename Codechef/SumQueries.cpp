#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int n,m;
	cin>>n>>m;
	long long int M[m];
	int i;
	for(i=0;i<m;i++){
		cin>>M[i];
		long long int L = max(M[i]-n,n+1);
		long long int R = min(M[i]-1,2*n);
		if(L>R)
			cout<<0<<endl;
		else
			cout<<R-L+1<<endl;
	}
}