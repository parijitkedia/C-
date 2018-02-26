#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(b!=0)
		return gcd(b,a%b);
	else
		return a;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int i,flag=0;
		int gcdval=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(i=0;i<n;i++){
			gcdval=gcd(gcdval,arr[i]);
			if(gcdval==1){
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<n<<endl;
		else
			cout<<-1<<endl;
	}
}
