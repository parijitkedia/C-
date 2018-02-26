#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;

	int q = n/7;
	int r = n%7;

	int w = q*5;
	int f = q*2;

	if(r>5){
		w+=5;
		f+=r-5;
	}else{
		w+=r;
	}
	cout<<min(n-w,f)<<" "<<max(n-w,f)<<endl;
}
