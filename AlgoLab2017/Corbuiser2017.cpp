#include <iostream>
#include <vector>

using namespace std;

bool solve(int n,int i,int k,vector<int> arr){
	
	vector<int> h_mod_k(n);
	for(int a = 0; a < n; a++) {
		h_mod_k[a] = arr[a] % k;
	}

	vector<vector<bool> > DP(n, vector<bool>(k, false));

	DP[0][0] = true;
	DP[0][h_mod_k[0]] = true;

	for(int a = 1; a < n; a++) {
		for(int b = 0; b < k; b++) {
			int i_take = (k+b-h_mod_k[a]) % k;
			DP[a][b] = DP[a-1][i_take] || DP[a-1][b];
		}
	}

	bool non_empty_solution = false;
	int a = n-1;
	int b = i;
	while(DP[a][b] && a > 0) {
		int i_take = (k+b-h_mod_k[a]) % k;
		if(DP[a-1][i_take]) {
			non_empty_solution = true;
			//b = i_take;
			break;
		} else {
			b = i;
		}
		a -= 1;
	}
	return non_empty_solution;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n,i,k;
		cin>>n>>i>>k;

		int j;
		vector<int> arr(n);
		for(j=0;j<n;j++){
			cin>>arr[j];
		}
		bool ans = solve(n,i,k,arr);
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}