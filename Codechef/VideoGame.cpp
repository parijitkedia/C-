#include <iostream>

using namespace std;

int main(){
	int n,h;
	cin>>n>>h;

	int arr[n];
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	int a,ctr=0;
	i=0;
	cin>>a;
	do{
		if(a==1){
			if(i==0)
				continue;
			else
				i--;
		}else if(a==2){
			i++;
		}else if(a==3){
			if(ctr==1){
				continue;
			}
			else if(arr[i]==0)
				continue;
			else{
				arr[i]--;
				ctr=1;
			}
		}else if(a==4){
			if(arr[i]+1>h){
				continue;
			}else{
				arr[i]++;
				ctr=0;
			}
		}
		cin>>a;
	}while(a!=0);

	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
