#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin>>n;
	vector<int> val(n);

	int sum=0,ans=0;
	int i,k=0;

	for(i=0;i<n;i++){
		cin>>val[i];
		sum+=val[i];
	}

	sort(val.rbegin(),val.rend());

	while(ans<=(sum-ans)){
		ans+=val[k];
		k++;
	}

	cout<<k<<endl;
	return 0;
}
