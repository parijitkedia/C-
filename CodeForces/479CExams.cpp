#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main(){
	int n;
	cin>>n;
	pair<int,int> arr[5000];
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+n);

	int ans=-1;
	for(i=0;i<n;i++){
		if(ans<=arr[i].second){
			ans=arr[i].second;
		}else{
			ans=arr[i].first;
		}
	}
	cout<<ans<<endl;
}
