#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n][3];
	int i,j;
	int sum=0;
	int count=0;
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<3;i++){
		sum=0;
		for(j=0;j<n;j++){
			sum+=arr[j][i];
		}
		//cout<<sum<<endl;
		if(sum==0)
			count++;
	}
	//cout<<n<<endl;
	if(count==3)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
