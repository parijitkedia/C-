#include <iostream>

using namespace std;

int main(){
	long long int t,s,x;
	cin>>t>>s>>x;

	long long int i;

	for(i=1;;i++){
		if(x==t + i*s || x==t + i*s + 1 || x==t){
			cout<<"YES"<<endl;
			break;
		}else{
			if(t + i*s >x || t+i*s+1>x){
				cout<<"NO"<<endl;
				break;
			}else
				continue;
		}
	}
}
