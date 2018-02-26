#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int t;
	int n,k;
	int sum=0;
	int min=9999999;
	int diff;
	int pos1,pos2;
	int i,j;

	cin>>t;

	while(t--){

		cin>>n>>k;
		int arr[n];

		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		for(i=0;i<n;i++){
			sum=0;
			for(j=i;j<n;j++){
				sum+=arr[j];
				diff=abs(k-sum);
				if(min>diff){
					min=diff;
					if(i!=j){
						pos1=i;
						pos2=j;
					}else{
						pos1=j;
						pos2=j;
					}
				}
			}
		}
		cout<<pos1<<" "<<pos2<<endl;
		sum=0;
		diff=0;
		min=9999999;
	}

}