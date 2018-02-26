#include <iostream>

using namespace std;

int gcd(int a,int b){

	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){

	int arr[2],n;
	int turn=0;

	cin>>arr[0]>>arr[1]>>n;

	while(n!=0){
		n=n-gcd(arr[turn],n);
		turn=turn^1;
	}
	if(turn==0)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}
