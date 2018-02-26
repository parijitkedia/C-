#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int ctr=0;
	while(a>0 && b>0){
		if(a<b){
			int temp = a;
			a=b;
			b=temp;
		}
		if(a<2)
			break;
		a=a-2;
		b=b+1;
		ctr++;
	}
	cout<<ctr<<endl;
}