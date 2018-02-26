#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;

	if(n==2){
		cout<<1<<endl;
		cout<<1<<endl;
	}else if(n==3){
		cout<<2<<endl;
		for(i=1;i<=n;i+=2){
			cout<<i<<" ";
		}
		cout<<endl;
	}else{
		cout<<n<<endl;

		if(n%2==0){
			for(i=n-1;i>=1;i-=2){
				cout<<i<<" ";
			}
			for(i=n;i>=2;i-=2){
				cout<<i<<" ";
			}
		}else{
			for(i=n;i>=1;i-=2){
				cout<<i<<" ";
			}
			for(i=n-1;i>=2;i-=2){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
}
