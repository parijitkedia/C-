#include <iostream>
#include <cstring>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int n,q;
	cin>>n>>q;

	int i,j;

	string str;
	int a,b;
	int maxv=-1;
	int row[n];
	int col[n];

	for(i=0;i<n;i++){
		row[i]=0;
		col[i]=0;
	}

	for(i=0;i<q;i++){
		cin>>str;
		cin>>a>>b;
		if(str[0]=='R'){
			row[a]+=b;
		}else{
			col[a]+=b;
		}
	}

	int mr=-1,mc=-1;
	for(i=0;i<n;i++){
		mr=max(mr,row[i]);
		mc=max(mc,col[i]);
	}

	cout<<mr+mc<<endl;
}
