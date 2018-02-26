#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int i;
	int sum=0;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum>=100 && sum<(100+x)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
}