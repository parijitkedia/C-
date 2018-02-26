#include <iostream>

using namespace std;

int main(){
	int s;
	cin>>s;
	int n;
	int mid;
	int i,k=1;
	while(s--){
		k=1;
		cin>>n;
		int arr[n];
		for(i=1;i<=n;i++){
			cin>>arr[i];
		}
		mid=n/2+1;

		if(n%2==0 || mid!=arr[mid])
			cout<<"no"<<endl;
		else{
			for(i=1;i<=mid;i++){
				if(arr[i]==k){
					k++;
				}
			}
			k=k-2;
			for(i=mid+1;i<=n;i++){
				if(arr[i]==k){
					k--;
				}
			}
			if(k==0)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}

	}
}
