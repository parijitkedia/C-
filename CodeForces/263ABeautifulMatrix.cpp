#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int arr[5][5];
	int i,j;
	int ith,jth;
	int flag=0;

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(arr[i][j]==1){
				ith=i;
				jth=j;
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	int res = abs(ith-2)+abs(jth-2);
	cout<<res<<endl;
	return 0;
}
