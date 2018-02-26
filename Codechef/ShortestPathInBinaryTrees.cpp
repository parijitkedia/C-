#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

int main(){
	int n;
	cin>>n;

	while(n--){
		lli a,b;
		cin>>a>>b;

		int arr[max(a,b)+1];

		int i,j=1,ctr=0,flag=0;
		arr[0]=0;
		arr[1]=0;
		for(i=2;i<=max(a,b);i++){
			if(i==2*j || i==2*j+1){
				arr[i]=j;
				ctr++;
				if( (a==2*j && b==2*j+1) || (a==2*j+1 && b==2*j) ){
					flag=1;
				}
			}
			if(ctr==2){
				j++;
				ctr=0;
			}
		}
		int pos1=0,pos2=0;
		int x;

		if(flag==1){
			cout<<2<<endl;
		}else{
			while(arr[a]!=0){
				x=arr[a];
				a=x;
				pos1++;
			}

			while(arr[b]!=0){
				x=arr[b];
				b=x;
				pos2++;
			}
			cout<<pos1+pos2<<endl;
		}
		
	}

}
