#include <iostream>

using namespace std;

int main(){
	int w;
	cin>>w;
	int i,j,flag=0;

	for(i=2;i<w;i=i+2){
		for(j=i;j<w;j=j+2){
			if(i+j==w){
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
