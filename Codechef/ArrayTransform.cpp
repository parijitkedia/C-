#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		vector<int> arr;
		int i,flag=0,maxv=-1;
		for(i=0;i<n;i++){
			int a;
			cin>>a;
			arr.push_back(a);
			maxv=max(maxv,a);
		}

		vector<int> ans(maxv+1,0);
		for(i=0;i<n;i++){
			ans[arr[i]]++;
			if(ans[arr[i]]==n-1){
				flag=1;
				break;
			}
		}

		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
