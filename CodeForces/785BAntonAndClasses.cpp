#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	int chess[n][2];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			cin>>chess[i][j];
		}
	}
	sort(chess,chess+n);

	int m;
	cin>>m;
	int prog[m][2];
	for(i=0;i<m;i++){
		for(j=0;j<2;j++){
			cin>>prog[i][j];
		}
	}
	sort(prog,prog+m);
	
	int dist=0,maxv=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(chess[i][1]<=prog[j][0]){
				dist=abs(chess[i][1]-prog[j][0]);
			}
		}
		maxv=max(maxv,dist);
	}
	cout<<maxv<<endl;
}