#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> s(n);
		vector<int> w(m);
		int maxs=-1;
		int maxw=-1;
		int i,j;

		for(i=0;i<n;i++){
			cin>>s[i];
			maxs=max(maxs,s[i]);
		}

		for(i=0;i<m;i++){
			cin>>w[i];
			maxw=max(maxw,w[i]);
		}
		int ctr=0;

		multiset<int, greater<int> > ws;
		sort(s.rbegin(),s.rend());

		if(maxw>maxs){
			cout<<"impossible"<<endl;
		}else{
			for(i=0;i<m;i++){
				ws.insert(w[i]);
			}
			while(!ws.empty()){
				++ctr;
				for(i=0;i<n;i++){
					auto b = ws.lower_bound(s[i]);
					//cout<<i<<" "<<s[i]<<" "<<*b<<" ";
					if(b!=ws.end()){
					//	cout<<"yes "<<endl;
						ws.erase(b);
					}else{
					//	cout<<"no ";
						break;
					}
				}
			}
			cout<<3*ctr-1<<endl;
		}
	}
}
