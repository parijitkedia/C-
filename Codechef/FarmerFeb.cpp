#include <iostream>
#include <cmath>

using namespace std;

bool check(int a){
	int i;
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0)
			return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		int sum=x+y;
		int i;
		int k=0,count=0;
		for(i=sum+1;;i++){
			bool ans=check(i);
			if(ans==true)
				break;
		}
		cout<<i-sum<<endl;
	}
}
