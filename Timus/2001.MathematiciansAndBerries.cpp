#include <iostream>

using namespace std;

int main(){
	int a[3],b[3];
	int i;
	for(i=0;i<3;i++){
		cin>>a[i]>>b[i];
	}

	cout<<a[0]-a[2]<<" "<<b[0]-b[1]<<endl;
}