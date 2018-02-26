#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	lli n;
	cin>>n;

	lli arr[n];
	lli i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	int ctr=1,pos=1;
	for(i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			pos++;
			ctr=max(ctr,pos);
		}else{
			pos=1;
			ctr=max(ctr,pos);
		}
	}
	cout<<ctr<<endl;
}
