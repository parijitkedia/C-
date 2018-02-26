#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,w;
		cin>>n>>w;
		int c[n],p[n],t[n];
		int i,j;

		for(i=0;i<n;i++){
			cin>>c[i]>>p[i]>>t[i];
		}

		for(i=0;i<n;i++){
			for(j=0;j<n-i-1;j++){
				if(t[j]>t[j+1]){
					int temp = t[j];
					int temp1 = c[j];
					int temp2 = p[j];
					t[j]=t[j+1];
					c[j]=c[j+1];
					p[j]=p[j+1];
					t[j+1]=temp;
					c[j+1]=temp1;
					p[j+1]=temp2;
				}
			}
		}

		int sum=0;
		for(i=0;i<n;i++){
			sum+=t[i];
			if(sum>w){
				break;
			}
		}
        sum=0;
		for(j=0;j<=i-1;j++){
            sum+=c[j]*p[j];
		}
		cout<<sum<<endl;
	}
}
