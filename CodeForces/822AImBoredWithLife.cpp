#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

long long int fact(long long int a){
	long long int f=1,i;
	for(i=a;i>=1;i--){
		f=f*i;
	}
	return f;
}

int main(){
	long long int a,b;
	cin>>a>>b;
	long long int ans= min(a,b);
	cout<<fact(ans)<<endl;
}


//#include <cmath>
//    cout << tgamma(n+1) << endl;
