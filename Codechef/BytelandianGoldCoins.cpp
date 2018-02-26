#include <iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

lli check(lli a){
	if(a<12){
		return a;
	}
	else{
		return max(a,check(a/2)+check(a/3)+check(a/4));
	}
}

int main(){

	lli n;
	while(cin>>n){
		cout<<check(n)<<endl;
	}
}