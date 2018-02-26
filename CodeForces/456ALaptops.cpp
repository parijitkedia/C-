#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b;
	int i,flag=0;
	for(i=0;i<n;i++){
		cin>>a>>b;
		if(a!=b)
			flag++;
	}
	if(flag==0)
		cout<<"Poor Alex"<<endl;
	else
		cout<<"Happy Alex"<<endl;
}