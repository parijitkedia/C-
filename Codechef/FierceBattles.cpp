#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> si;
		vector<int> sf;
		int i;

		for(i=1;i<=100;i++){
			si.push_back(0);
		}

		for(i=1;i<=100;i++){
			sf.push_back(0);
		}

		int c,l;
		int ans=0;
		for(i=1;i<=n;i++){
			cin>>c>>l;
			si[l]+=c;
		}

		for(i=1;i<=m;i++){
			cin>>c>>l;
			sf[l]+=c;
		}

		for(i=1;i<=100;i++){
			if(sf[i]-si[i]>0){
				ans+=sf[i]-si[i];
			}
		}
		cout<<ans<<endl;

	}
}