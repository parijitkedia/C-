#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int arr[100];
	int val[5];
	int i;
	int sum=0;
	for(i=1;i<=5;i++){
		cin>>val[i];
		sum+=val[i];
	}

	for(i=1;i<=100;i++){
		arr[i]=0;
	}

	for(i=1;i<=5;i++){
		arr[val[i]]++;
	}

	int minv=999,flag=0;
	int a;
	for(i=1;i<=100;i++){
		if(arr[i]>=3){
			flag=1;
			a = sum - 3*i;
			minv = min(a,minv);
		}else{
			if(arr[i]>1){
				flag=1;
				a = sum - 2*i;
				minv = min(a,minv);
			}
		}
	}
	if(flag==1)
		cout<<minv<<endl;
	else
		cout<<sum<<endl;

}
