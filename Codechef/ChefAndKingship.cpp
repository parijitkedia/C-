#include <iostream>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;

		lli arr[n];
		lli i;

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

		lli f = arr[0];
        lli sum=0;
		for(i=1;i<n;i++){
			sum+=f*arr[i];
		}
		cout<<sum<<endl;
	}
}
