#include <iostream>
#include <cmath>

using namespace std;

int check(int arr[], int n)
{
	int table[n][n], gap, i, j, x, y, z;

	for (gap = 0; gap < n; ++gap)
	{
		for (i = 0, j = gap; j < n; ++i, ++j)
		{
			x = ((i+2) <= j) ? table[i+2][j] : 0;
			y = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
			z = (i <= (j-2))? table[i][j-2]: 0;

			table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
		}
	}
	return table[0][n-1];
}

int main()
{
	int t;
	int n;
	cin>>t;
	int i;

	while(t--){
		cin>>n;
		int arr[n];

		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<check(arr,n)<<endl;
	}
	return 0;
}
