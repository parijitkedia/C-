#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i,j,ctr=0;
	int a=n/2;
	int b=n%2;
	cout<<(a+b)*(a+b) + a*a<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i%2!=0){
				if(j%2!=0){
					cout<<"C";
				}else{
					cout<<".";
				}
			}else{
				if(j%2==0){
					cout<<"C";
				}else{
					cout<<".";
				}
			}
		}
		cout<<endl;
	}
	cout<<endl;
}