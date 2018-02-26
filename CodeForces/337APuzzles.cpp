#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int n,m;
	int i;
	cin>>n>>m;

	vector<int> val(m);
	int arr[1000000];
	int count=0;
	for(i=0;i<m;i++){
		cin>>val[i];
	}

	sort(val.begin(),val.end());

	i=0;
	while(i+n-1!=m){
		arr[i]=val[i+n-1]-val[i];
		count++;
		i++;
	}

	sort(arr,arr+count);
	cout<<arr[0]<<endl;
}
