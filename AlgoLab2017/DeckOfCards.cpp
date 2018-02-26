#include <iostream>
#include <cmath>
#include <climits>

typedef long long int lli;

using namespace std;

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n,k;
		cin>>n>>k;

		lli arr[n];
		lli i,j;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		lli sum=arr[0];
		lli minv=INT_MAX;
		i=0,j=0;
		lli pos1,pos2;
		while(i<n){
		//	minv = min(minv,abs(sum-k));
			if(minv>abs(sum-k)){
				//cout<<"here"<<endl;
				minv=abs(sum-k);
				if(i!=j){
					pos1=i;
					pos2=j;
				}else{
					pos1=j;
					pos2=j;
				}
			}
			if(sum<k && j<n){
				j++;
				sum+=arr[j];
			}else{
				sum-=arr[i];
				i++;
			}
		}
		cout<<pos1<<" "<<pos2<<endl;
	}
}
