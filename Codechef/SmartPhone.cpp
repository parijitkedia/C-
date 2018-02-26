#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

int main(){
	ios_base::sync_with_stdio(false);
	lli n;
	cin>>n;

	vector<lli> arr;
	lli i,j,a;
	for(i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}

	lli sum=0;
	lli maxv=-1;
	for(i=0;i<n;i++){
		a=arr[i];
		for(j=0;j<n;j++){
			if(arr[j]>=a){
				sum+=arr[i];
			}
		}
		//cout<<sum<<endl;
		maxv=max(maxv,sum);
		sum=0;
	}
	cout<<maxv<<endl;
}
