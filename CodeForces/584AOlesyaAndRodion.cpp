#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long n,t;

	cin>>n>>t;
	int j;
	long long i=1;
	if(n==1 && t==10)
		cout<<-1<<endl;
	else{
		cout<<t;
		if(t==10)
			i++;
		for(j=i;j<n;j++)
			cout<<0;
	}
}
