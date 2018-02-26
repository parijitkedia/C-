#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		long int n,m,k;
		cin>>n>>m>>k;

		vector<long int> arr(n);
		int i,j;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		i=0,j=0;
		long int sum=arr[0];
		vector<long int> ans(n,0);
		while(i<n && j<n){
			if(sum<k){
				j++;
				sum+=arr[j];
			}else if(sum>k){
				sum-=arr[i];
				i++;
			}else{
				ans[j]=j-i+1;
				sum-=arr[i];
				i++;
			}
		}

		long int dp[10000][101];
		for(i=0;i<=n;i++){
			dp[i][0]=0;
		}
		for(i=0;i<=m;i++){
			dp[0][i]=0;
		}

		for(i=1;i<=m;i++){
			for(j=0;j<=n;j++){
				if(i>j)
					dp[i][j]=0;
				else{
					dp[i][j]=max( dp[i-1][j-ans[j-1]]+ans[j-1], dp[i][j-1]);
				}
			}
		}

		/*for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/

		if(dp[m][n]!=dp[m-1][n])
			cout<<dp[m][n]<<endl;
		else
			cout<<"fail"<<endl;
	}
}
