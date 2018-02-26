#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,c;
	cin>>n>>c;
	vector<int> arr(n);

	int count=0;
	int i;
		
	for(i=0;i<n;i++)
		cin>>arr[i];

	for(i=1;i<n;i++){
		if(arr[i]-arr[i-1]<=c)
			count++;
		else
			count=0;
	}
	cout<<count+1<<endl;
}