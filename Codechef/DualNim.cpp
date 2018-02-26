#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int a;
		int i,sum=0;
		for(i=0;i<n;i++){
			cin>>a;
			sum=sum^a;
		}

		if(sum==0){
			cout<<"First"<<endl;
		}else{
			if(n%2==0){
				cout<<"First"<<endl;
			}else{
				cout<<"Second"<<endl;
			}
		}
	}
}
