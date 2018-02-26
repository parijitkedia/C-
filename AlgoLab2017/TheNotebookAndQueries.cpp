#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

int main(){
	int t;
	cin>>t;
	while(t--){
		lli k,n,q;
		cin>>k>>n>>q;
		lli i,j,l;
		for(i=0;i<k;i++){
			lli a,b;
			cin>>a>>b;
		}

		lli arr[n][k+1];
		for(i=0;i<n;i++){
			for(j=0;j<k+1;j++){
				cin>>arr[i][j];
			}
		}

		lli val[q][k];
		for(i=0;i<q;i++){
			for(j=0;j<k;j++){
				cin>>val[i][j];
			}
		}
		lli ctr=0,flag=0;
		for(i=0;i<q;i++){
			ctr=0;
			flag=0;
			for(j=0;j<n;j++){
				ctr=0;
				for(l=0;l<k;l++){
					if(val[i][l]==arr[j][l]){
						//cout<<"ctr: "<<ctr<<" "<<"i: "<<i<<" j: "<<j<<" l: "<<l<<endl;
						ctr++;
					}
					if(ctr==k){
						cout<<arr[j][k]<<endl;
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}
			if(flag==0){
				cout<<-1<<endl;
			}
		}
	}
}
