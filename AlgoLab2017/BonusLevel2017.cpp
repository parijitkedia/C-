#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n,vector<vector<int> >& arr){
	
	vector<vector<vector<int> > > state(2*n-1, vector<vector<int> > (n, vector<int>(n,0)));
	vector<vector<vector<bool> > > bound(2*n, vector<vector<bool> > (n+1, vector<bool> (n+2,false)));

	for(int d = 2*n-2; d>=0;d--){
		for(int x1 = 0; x1<n; x1++){
			for(int x2 = 0; x2<n; x2++){

				int y1 = d-x1;
				int y2 = d-x2;
				bound[d][x1][x2] = y1>=0 && y1<n && y2>=0 && y2<n;
			}
		}
	}

	for(int d = 2*n-2; d>=0; d--){
		for(int x1 = 0; x1<n; x1++){

			int y1=d-x1;
			if(!(y1>=0 && y1<n))
				continue;

			for(int x2 = 0; x2<n; x2++){

				int y2=d-x2;
				if(!(y2>=0 && y2<n))
					continue;

				int m=0;
				if(bound[d+1][x1][x2])
					m=max(m,state[d+1][x1][x2]);
				if(bound[d+1][x1+1][x2])
					m=max(m,state[d+1][x1+1][x2]);
				if(bound[d+1][x1][x2+1])
					m=max(m,state[d+1][x1][x2+1]);
				if(bound[d+1][x1+1][x2+1])
					m=max(m,state[d+1][x1+1][x2+1]);

				state[d][x1][x2]=arr[x1][y1]+arr[x2][y2]+m;
				if(x1==x2 && y1==y2)
					state[d][x1][x2]-=arr[x1][y1];
			}
		}
	}
	return state[0][0][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector<vector<int> > arr(n,vector<int>(n));
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		cout<<solve(n,arr)<<endl;
	}
}