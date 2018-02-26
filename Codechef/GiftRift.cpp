#include <iostream>
#include <cmath>
#include <climits>

typedef long long int lli;

using namespace std;

int main(){
	lli r,c;
	cin>>r>>c;

	lli arr[r][c];
	lli i,j;
	bool ans;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}

	lli row[r];
	lli col[c];
	lli minv=99999999;
	lli maxv=-1;
	for(i=0;i<r;i++){
		minv=99999999;
		for(j=0;j<c;j++){
			minv=min(minv,arr[i][j]);
		}
		row[i]=minv;
	}

	for(i=0;i<c;i++){
		maxv=-1;
		for(j=0;j<r;j++){
			maxv=max(maxv,arr[j][i]);
		}
		col[i]=maxv;
	}

	lli flag=0;
	for(i=0;i<r;i++){
		flag=0;
		for(j=0;j<c;j++){
			if(row[i]==col[j]){
				cout<<row[i]<<endl;
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==0){
		cout<<"GUESS"<<endl;
	}
}
