#include <iostream>
#include <vector>

using namespace std;

int main(){

	int t;
	int n;
	cin>>t;

	while(t--){
		cin>>n;
		
		int arr[n][n];
		int sum=0;
		int count=0;
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}

		int i1,j1,i2,j2,k1,k2;
		for(i1=0;i1<n;i1++){
			for(j1=0;j1<n;j1++){
				for(i2=i1;i2<n;i2++){
					for(j2=j1;j2<n;j2++){
						sum=0;
						for(k1=i1;k1<=i2;k1++){
							for(k2=j1;k2<=j2;k2++){
								sum=sum+arr[k1][k2];
							}
						}
						if(sum%2==0)
							count++;
					}
				}
			}
		}
		cout<<count<<endl;
	}
}
