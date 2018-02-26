#include <iostream>

using namespace std;

int main(){
	long long int n,m;

	cin>>n>>m;

	if(n-m>=m){
		cout<<m+1<<endl;
	}else if(m>1){
		cout<<m-1<<endl;
	}else{
		cout<<1<<endl;
	}
}
