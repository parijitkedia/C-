#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(){
	lli n;
	cin>>n;
	lli i,a;
	vector<int> arr;

	for(i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
    lli ctr=0;
	for(i=1;i<n;i++){
		if(arr[i]>arr[0] && arr[i]<arr[n-1]){
			ctr++;
		}
	}
	cout<<ctr<<endl;

}
