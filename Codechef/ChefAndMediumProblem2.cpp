#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> arr(n+1);
	int i,j;
	arr.push_back(0);
	for(i=1;i<n+1;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	int m;
	cin>>m;

	for(i=1;i<=m;i++){
		int a;
		cin>>a;
		if(a==1){
			int l,r,p;
			cin>>l>>r>>p;
			for(j=l;j<=r;j++){
				if(arr[j]%2==0){
					arr[j]=arr[j]/2;
				}
				if(arr[j]%3==0){
					arr[j]=arr[j]/3;
				}
				if(arr[j]%5==0){
					arr[j]=arr[j]/5;
				}
			}
		}else{
			int l,d;
			cin>>l>>d;
			arr[l]=d;
		}
	}

	for(i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
