#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		string s;
		cin>>s;
		long long int i;
		long long int count=0;
		for(i=0;i<n;i++){
			if(s[i]=='1'){
				count++;
			}
		}
		long long int ans=(count*(count+1))/2;
		cout<<ans<<endl;
	}
}