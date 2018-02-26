#include <iostream>

typedef long long int lli;

using namespace std;

int main(){
	lli n,m,c;
	cin>>n>>m>>c;

	lli i,j;
	lli arr[n];
	for(i=0;i<n;i++){
		arr[i]=c;
	}

	for(i=0;i<m;i++){
		char ch;
		cin>>ch;
		if(ch=='S'){
			lli u,v,k;
			cin>>u>>v>>k;
			for(j=u-1;j<v;j++){
				arr[j]+=k;
			}
		}
		if(ch=='Q'){
			lli p;
			cin>>p;
			cout<<arr[p-1]<<endl;
		}
	}
}
