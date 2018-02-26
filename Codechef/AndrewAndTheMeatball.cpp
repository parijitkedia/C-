#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		lli n,m;
		cin>>n>>m;

		vector<lli> arr;
		lli a;
        lli i,sum=0;
		for(i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}

        lli flag=0;
		sort(arr.begin(),arr.end());

		for(i=n-1;i>=0;i--){
			sum+=arr[i];
			if(sum>=m){
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<n-i<<endl;
		else
			cout<<-1<<endl;
	}
}
