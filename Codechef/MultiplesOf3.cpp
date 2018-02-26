#include <iostream>

using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	int i,j;
	int num,a,b;
	int arr[n];
	int ctr=0;
	for(i=0;i<n;i++){
		arr[i]=0;
	}

	for(i=0;i<q;i++){
		cin>>num>>a>>b;
		if(num==0){
			for(j=a;j<=b;j++){
				arr[j]++;
			}
		}else{
			for(j=a;j<=b;j++){
				if(arr[j]%3==0){
					ctr++;
				}
			}
			cout<<ctr<<endl;
		}
		ctr=0;
	}
}
