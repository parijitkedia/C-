#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int t;
	cin>>t;
	int m,i;
	double num,sum=0;
	while(t--){
		cin>>m;
		sum=0;
		for(i=0;i<m;i++){
			cin>>num;
			sum+=num;
		}
		cout<<fixed<<setprecision(4)<<sum<<endl;
	}

}
