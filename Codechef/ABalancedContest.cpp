#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n,p;
		cin>>n>>p;

		lli arr[n];
		lli i;

		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		lli a = p/2;
		lli b = p/10;
		lli h=0,c=0;
		for(i=0;i<n;i++){
			if(arr[i]<=b)
				h++;
			else if(arr[i]>=a)
				c++;
		}

		if(h==2 && c==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	
}