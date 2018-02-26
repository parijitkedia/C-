#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,c;
		cin>>n>>m>>c;
		int i,j;
		int count=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i*j==c)
					count++;
			}
		}
		cout<<count<<endl;
	}
}