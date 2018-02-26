#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	string str;
	int b,a,flag=0;;

	for(i=0;i<n;i++){
		cin>>str;
		cin>>b>>a;
		if(a>b && a>=2400 && b>=2400){
			flag=1;
		}
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
