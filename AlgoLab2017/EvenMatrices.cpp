#include <iostream>
#include <vector>

using namespace std;

int evenpairs(vector<int>& in){
	int n = in.size()-1;

	vector<int> sum(n);
	int i;
	for(i=0;i<n;i++){
		int temp = in[i+1];
		if(i==0){
			sum[i]=temp;
		}
		sum[i]=sum[i-1]+temp;
	}
	int even = 0, odd = 0;
	for(int i=0;i<n;i++){
		if(sum[i]%2==0){
			even++;
		}
		else{
			odd++;
		}
	}
	return (even*(even+1)/2 + odd*(odd-1)/2);
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int arr[n][n];
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}

		int sum[n+1][n+1];
		for(i=0;i<=n;i++){
			sum[0][i]=0;
			sum[i][0]=0;
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i-1][j-1];
			}
		}

		int ctr=0;
		int i1,i2;
		for(i1=1;i1<=n;i1++){
			for(i2=i1;i2<=n;i2++){
				vector<int> col(n+1);
				col[0]=0;
				for(j=1;j<=n;j++){
					col[j]=sum[i2][j]-sum[i2][j-1]-sum[i1-1][j]+sum[i1-1][j-1];
				}
				ctr += evenpairs(col);
			}
		}
		cout<<ctr<<endl;
	}
}
