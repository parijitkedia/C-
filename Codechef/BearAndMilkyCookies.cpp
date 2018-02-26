#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int i,flag;
	while(t--){
		flag=0;
		cin>>n;
		char arr[n][7];
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		for(i=0;i<n;i++){
			if(strcmp(arr[i],"cookie")==0){
				if(strcmp(arr[i+1],"milk")==0){
					continue;
				}
				else{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
