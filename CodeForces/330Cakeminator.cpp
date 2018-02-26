#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int r,c;

	cin>>r>>c;
	int ctr=0,ans=0;
	char arr[r][c];

	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<r;i++){
		ctr=0;
		for(j=0;j<c;j++){
			if(arr[i][j]=='.'){
				ctr++;
			}
		}
		if(ctr==c){
            ans+=ctr;
		}
	}

    ctr=0;
	for(i=0;i<c;i++){
		ctr=0;
		for(j=0;j<r;j++){
			if(arr[j][i]=='.'){
				ctr++;
			}
		}
		if(ctr==r){
            ans+=ctr;
		}
	}
	cout<<ans<<endl;
}
