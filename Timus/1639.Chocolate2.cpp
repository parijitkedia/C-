#include <iostream>

using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	if((m*n)%2==0)
		cout<<"[:=[first]"<<endl;
	else
		cout<<"[second]=:]"<<endl;
}