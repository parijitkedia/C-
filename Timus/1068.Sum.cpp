#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i,sum=0;
	if(n<1){
		for(i=1;i>=n;i--){
			sum+=i;
		}
	}else{
		for(i=1;i<=n;i++){
			sum+=i;
		}
	}
	cout<<sum<<endl;
}