#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int res[n];
	int val[n];
	int i;
	for(i=1;i<=n;i++){
		res[i]=0;
		cin>>val[i];
	}

	for(i=1;i<=n;i++){
		res[val[i]]=1;
	}

	for(i=1;i<=n;i++){
		if(res[i]==1)
			cout<<i<<endl;
	}
}
