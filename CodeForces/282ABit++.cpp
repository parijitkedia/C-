#include <iostream>

using namespace std;

int main(){

	int n;
	int i;
	int ans=0;
	cin>>n;

	while(n--){
		string x;
		cin>>x;
		for(i=0;i<x.size();i++){
			if(x[i]=='+'){
				ans++;
				break;
			}
			if(x[i]=='-'){
				ans--;
				break;
			}
		}
	}

	cout<<ans<<endl;
}