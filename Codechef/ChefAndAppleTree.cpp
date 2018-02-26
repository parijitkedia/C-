#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int val[n];
		int i;

		for(i=1;i<=n;i++){
			cin>>arr[i];
			val[i]=0;
		}

		for(i=1;i<=n;i++){
			val[arr[i]]++;
		}

		int ctr=0;
		for(i=1;i<=n;i++){
			if(val[i]!=0)
				ctr++;
		}
		cout<<ctr<<endl;
	}
}
