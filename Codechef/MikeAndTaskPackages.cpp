#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,x;
	cin>>n>>x;

	int i;
	vector<int> arr(n);
	for(i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	sort(arr.begin(),arr.end());
	int sum=0;
	int l=0,w=0;
	for(i=0;i<n;i++){
		sum+=arr[i];
		if(sum<=x){
			w++;
		}
		if(sum>x){
			int a = sum-x;
			if(a>arr[i]/2){
				break;
			}
		}
	}
	cout<<l<<" "<<w<<endl;
}
