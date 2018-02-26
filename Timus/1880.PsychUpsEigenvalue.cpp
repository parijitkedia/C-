#include <iostream>

using namespace std;

int main(){
	long long int i;
	long long int n,a;
	long long int t=3,ctr=0;
	unsigned long int res[4001]={0};

	while(t--){
		cin>>n;

		for(i=0;i<n;i++){
			cin>>a;
			res[a]++;
			if(res[a]==3)
				ctr++;
		}
	}
	cout<<ctr<<endl;
}
