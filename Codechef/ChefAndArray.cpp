#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> arr;
	int i,j;

	for(i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	int m,x,y;
	cin>>m>>x>>y;
	int a = min(x,y);
	int b = max(x,y);
	int ans=-1,sum=0;

	for(i=a;i<=b;i++){
	//	cout<<arr[i]<<" ";
		ans=max(ans,arr[i]);
	}
	sum+=ans;
	//cout<<sum<<endl;
	for(i=1;i<m;i++){
		x = (x+7)%(n-1);
		y = (y+11)%n;
	//	cout<<x<<" "<<y<<endl;
		a = min(x,y);
		b = max(x,y);
		for(j=a;j<=b;j++){
			ans=max(ans,arr[j]);
		}
		sum+=ans;
	//	cout<<sum<<endl;
		ans=0;
	}
	cout<<sum<<endl;
}
