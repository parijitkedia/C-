#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int i;
	int arr[m],res[n];

	for(i=1;i<=n;i++)
		res[i]=0;

	for(i=1;i<=m;i++){
		cin>>arr[i];
	}

	for(i=1;i<=m;i++){
		res[arr[i]]++;
	}

	for(i=1;i<=n;i++){
		cout<<fixed<<setprecision(2)<<100*(double)res[i]/m<<"%"<<endl;
	}
}
