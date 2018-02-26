#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int i,j;
	int ctr=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if( (i*i)+j==n && (j*j)+i==m )
				ctr++;
		}
	}
	cout<<ctr<<endl;
}
