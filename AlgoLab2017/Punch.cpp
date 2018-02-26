#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n,int k,vector<int>& c, vector<int>& v){

	if(k==0){
		cout<<0<<" "<<0<<endl;
		return;
	}

	int maxv = k + *max_element(v.begin(),v.end());
	vector<vector<pair<int,int> > > dp(n,vector<pair<int,int> >(maxv+1));

	int i,j;
	dp[0][0]=make_pair(0,0);
	for(j=1;j<=maxv;j++){
		int needed = (j+v[0]-1)/v[0];
		dp[0][j]=make_pair(needed*c[0],1);
	}

	for(i=1;i<n;i++){
		dp[i][0]=dp[i-1][0];
		for(j=1;j<=maxv;j++){
			auto takenone = dp[i-1][j];
			int mincost,maxnum;
			if(j<v[i]){
				mincost=c[i];
				maxnum=1;
			}else{
				pair<int,int> takeone = dp[i][j-v[i]];
				mincost=takeone.first + c[i];
				maxnum = takeone.second + (dp[i-1][j-v[i]] == dp[i][j-v[i]] ? 1:0);
			}
			if(takenone.first<mincost){
				mincost=takenone.first;
				maxnum=takenone.second;
			}else if(takenone.first==mincost){
				maxnum=max(maxnum,takenone.second);
			}
			dp[i][j]=make_pair(mincost,maxnum);
		}
	}
	cout<<dp[n-1][k].first<<" "<<dp[n-1][k].second<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		vector<int> c(n),v(n);
		int i;
		for(i=0;i<n;i++){
			cin>>c[i];
			cin>>v[i];
		}
		solve(n,k,c,v);
	}
}