#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
    int i;
	for(i=0;i<n;i++)
		cin>>arr[i];

	sort(arr.begin(),arr.end());
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
