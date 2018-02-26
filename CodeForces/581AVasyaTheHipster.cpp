#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
    int same,diff;
	if(a-b>0){
		 diff=b;
		 a=(a-b)/2;
		 same=a;
	}else{
		diff=a;
		b=(b-a)/2;
		same=b;
	}
	cout<<diff<<" "<<same<<endl;
}
