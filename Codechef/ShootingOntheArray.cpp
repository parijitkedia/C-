#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,q;
		cin>>n>>q;

		int arr[n];
		int i,j;

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		for(i=0;i<q;i++){
			char ch;
			cin>>ch;
			if(ch=='+'){
				int j,x;
				cin>>j>>x;

			}
			if(ch=='?'){
				int j,l,r;
				cin>>j>>l>>r;
				
			}
		}
	}
}