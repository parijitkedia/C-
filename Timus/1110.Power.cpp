#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long int ans,n,m,y,i,j,flag=0,sum=1;
	cin>>n>>m>>y;

	for(i=1;i<=m;i++){
		sum=pow(i,n);
		if(sum%m==y){
			flag=1;
			cout<<i<<" ";
		}
	}
	cout<<endl;
	if(flag==0)
		cout<<-1<<endl;
}
