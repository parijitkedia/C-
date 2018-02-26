#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		int i,j,k;
		vector<int> b;
		for(i=0;i<m;i++){
			int a;
			cin>>a;
			b.push_back(a);
		}

		int on[n][m],off[n][m];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				int a,b;
				cin>>a>>b;
				on[i][j]=a;
				off[i][j]=b;
			}
		}
		int min=n+1;
		bool flag;

		for(i=(1<<n)-1;i>0;i--){
			for(j=0;j<m;j++){
				int sum=0;
				for(k=0;k<n;k++){
					if(i&(1<<k))
						sum+=on[k][j];
					else
						sum+=off[k][j];

					if(sum>b[j])
						break;
				}

				if(sum==b[j])
					flag=false;
				else
					flag=true;

				if(flag)
					break;
			}
			if(!flag){
				int ctr=0;
				for(j=0;j<n;j++){
					if(!(i&1<<j))
						ctr++;
				}
				if(min>ctr)
					min=ctr;
			}
		}
		if(min==n+1)
			cout<<"Impossible"<<endl;
		else
			cout<<min<<endl;
	}
}