#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	long long int n;
	int i;
	long long int sum1=0,sum2=0;
	while(t--){
		sum1=0,sum2=0;
		cin>>n;
		long long int x[n];
		long long int y[n];
		for(i=1;i<=n;i++){
			cin>>x[i];
		}
		for(i=1;i<=n;i++){
			cin>>y[i];
		}
		for(i=1;i<=n;i++){
			if(i%2==1){
				sum1+=x[i];
				sum2+=y[i];
			}else{
				sum1+=y[i];
				sum2+=x[i];
			}
		}
		if(sum1<sum2)
			cout<<sum1<<endl;
		else
			cout<<sum2<<endl;
	}
}