#include <iostream>
#include <vector>

using namespace std;

int main(){

	int t,i,n;
	float sum=0,val;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>val;
			sum+=val;
		}
		cout<<sum<<endl;
		sum=0;
	}
}