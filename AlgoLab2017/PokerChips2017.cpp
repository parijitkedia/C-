#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int n, vector<int>& height, vector<vector<int> >& stack, vector<vector<vector<vector<vector<int> > > > >& dp, vector<int>& arr){

	if(dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]]==-1){
		int maxv = -1;

		int i,j;
		for(i=1;i<(1<<n);i++){

			int color=-1;
			bool valid=true;
			int removed=0;
			vector<int> newarr(5);

			for(j=0;j<n;j++){
				if((i>>j)&1){
					if(arr[j]==0){
						valid=false;
						break;
					}
					if(color==-1){
						color = stack[j][arr[j]-1];
					}else if(color!=stack[j][arr[j]-1]){
						valid=false;
						break;
					}
					removed++;
					newarr[j]=arr[j]-1;
				}else{
					newarr[j]=arr[j];
				}
			}

			if(valid){
				int ctr=0;
				if(removed>1){
					ctr=pow(2,removed-2);
				}
				int val = ctr + solve(n,height,stack,dp,newarr);
				maxv=max(maxv,val);
			}
		}
		dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]]=maxv;
	}
	return dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> height(5,0);
		vector<int> arr(5,0);

		int i,j;
		for(i=0;i<n;i++){
			int a;
			cin>>a;

			height[i]=a;
			arr[i]=a;
		}

		vector<vector<int> > stack;
		stack.reserve(n);

		for(i=0;i<n;i++){
			stack.push_back(vector<int>(height[i],-1));
			for(j=0;j<height[i];j++){
				cin>>stack[i][j];
			}
		}

		vector<vector<vector<vector<vector<int> > > > > dp(height[0]+1,
			vector<vector<vector<vector<int> > > >(height[1]+1,
				vector<vector<vector<int> > >(height[2]+1,
					vector<vector<int> > (height[3]+1,
						vector<int> (height[4]+1,-1)))));

		dp[0][0][0][0][0]=0;
		cout<<solve(n,height,stack,dp,arr)<<endl;
	}
}


/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> height(n);
		vector<vector<int> >stack;

		int i,j;
		for(i=0;i<n;i++){
			cin>>height[i];
			vector<int> a;
			stack.push_back(a);
		}

		for(i=0;i<n;i++){
			stack[i].push_back(-1);
			for(j=0;j<height[i];j++){
				int a;
				cin>>a;
				stack[i].push_back(a);
			}
		}

		vector<vector<int> >dp(1025,vector<int>(1025,0));
		for(i=1;i<=height[0];i++){
			for(j=1;j<=height[1];j++){
				int m = stack[0][i] == stack[1][j];
				dp[i][j]=max(dp[i-1][j], max(dp[i][j-1],dp[i-1][j-1]+m));
			}
		}
		cout<<dp[height[0]][height[1]]<<endl;
	}
}*/