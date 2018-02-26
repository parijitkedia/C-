#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n,q;
	cin>>n>>q;

	int num;
	int i,j;
	int a,b;
	int ctr=0;

	int arr[n];
	for(i=0;i<n;i++){
		arr[i]=0;
	}

	for(i=0;i<q;i++){
		cin>>num>>a>>b;
		if(num==1){
			for(j=a;j<=b;j++){
				if(arr[j]==1){
					ctr++;
				}
			}
			cout<<ctr<<endl;
			ctr=0;
		}else{
			for(j=a;j<=b;j++){
				if(arr[j]==0)
					arr[j]=1;
				else
					arr[j]=0;
			}
		}
	}
}
