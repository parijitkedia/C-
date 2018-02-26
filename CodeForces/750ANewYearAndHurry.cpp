#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int i=1;
	int sum=k;
	int ctr=0;
	do{
		sum+=(5*i);
		//cout<<i<<" "<<sum<<endl;
		i++;
		ctr++;
	}while(sum<=240 && ctr<=n);
	cout<<ctr-1<<endl;
}
