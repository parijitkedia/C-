#include <iostream>

typedef long long int lli;

using namespace std;

lli check(lli set[], lli n, lli sum)
{
	lli subset[n+1][sum+1];

	for (lli i = 0; i <= n; i++)
		subset[i][0] = 1;

	for (lli i = 1; i <= sum; i++)
		subset[0][i] = 0;

	for (lli i = 1; i <= n; i++)
	{
		for (lli j = 1; j <= sum; j++)
		{
			if(j<set[i-1])
				subset[i][j] = subset[i-1][j];
			if (j >= set[i-1])
				subset[i][j] = subset[i-1][j] + subset[i - 1][j-set[i-1]];
		}
	}
	return subset[n][sum];
}

int main(){
	lli n;
	cin>>n;

	lli arr[n];
	lli i,j,k;

	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	lli q;
	cin>>q;
	lli p;
	for(k=0;k<q;k++){
		cin>>p;

		lli x = check(arr,n,p);
		if(x>=1){
			cout<<"yes "<<x<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}
