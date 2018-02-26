#include <iostream>
#include <vector>
using namespace std;

int main(){

	int n,k;
	int i;

	cin>>n>>k;
	int count=0;

	vector<int> val(n);

	for(i=0;i<n;i++)
		cin>>val[i];

	for(i=0;i<n;i++){
		if(val[i]>=val[k-1] && val[i]>0 )
			count++;
	}

	cout<<count<<endl;
}
