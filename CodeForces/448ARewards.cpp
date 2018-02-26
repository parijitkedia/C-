#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	int A[3],B[3];
	int i;
    int sumA=0,sumB=0;
	for(i=0;i<3;i++){
		cin>>A[i];
		sumA+=A[i];
	}

	for(i=0;i<3;i++){
		cin>>B[i];
		sumB+=B[i];
	}

	cin>>n;
	sumA+=4;
	sumB+=9;
	int ans = (sumA/5)+(sumB/10);
	if(ans<=n)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}
