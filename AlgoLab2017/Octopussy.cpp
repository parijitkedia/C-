#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> arr;
		int a;
		cin>>a;
		arr.push_back(a);

		int i;
		int flag=0;
		for(i=1;i<n;i++){
			cin>>a;
			a = min( arr[(i-1)/2]-1,a );
			arr.push_back(a);
		}

		sort(arr.begin(),arr.end());

		for(i=0;i<n;i++){
			if(i>=arr[i]){
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
}
