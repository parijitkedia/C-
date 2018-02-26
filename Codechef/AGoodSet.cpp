#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int i,j,ctr;
	while(t--){
        ctr=0;
		cin>>n;
		for(i=1;;i+=2){
			ctr++;
			cout<<i<<" ";
			if(ctr==n)
				break;
		}
		cout<<endl;
	}
}
