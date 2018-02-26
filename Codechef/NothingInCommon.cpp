#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n,m;
	int i,j,ctr;
	while(t--){
		ctr=0;
		cin>>n>>m;
		int a[n],b[m];
		int ans[100000];
		for(i=1;i<=100000;i++){
			ans[i]=0;
		}
		for(i=1;i<=n;i++){
			cin>>a[i];
			ans[a[i]]++;
		}
		for(i=1;i<=m;i++){
			cin>>b[i];
			ans[b[i]]++;
		}
		for(i=1;i<=100000;i++){
			if(ans[i]==2)
				ctr++;
		}
		cout<<ctr<<endl;
	}
}
