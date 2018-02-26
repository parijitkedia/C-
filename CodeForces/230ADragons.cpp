#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int s,n;

	cin>>s>>n;

	pair<int, int> arr[1000];
	int count=0;
    int i;
	for(i=0;i<n;i++)
		cin>>arr[i].first>>arr[i].second;

	sort(arr,arr+n);

	for(i=0;i<n;i++){
		if(s>arr[i].first){
			s=s+arr[i].second;
			count++;
		}
	}
	if(count==n)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}
