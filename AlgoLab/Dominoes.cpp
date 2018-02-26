#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> height(n);
		int i;
		int flag=0;
		int l=0;
		for(i=0;i<n;i++)
			cin>>height[i];

		for(i=0;i<n;i++){
			l=max(i+height[i]-1,l);
			if(i>=l){
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<l+1<<endl;
		else
			cout<<n<<endl;
	}
}
