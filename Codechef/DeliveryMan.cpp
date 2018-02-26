#include <iostream>

using namespace std;

int main(){
	int n,x,y;
	cin>>n>>x>>y;
	int i;
	int A[n],B[n];
	for(i=0;i<n;i++){
		cin>>A[i];
		cin>>B[i];
	}
	sort(A,A+n);
	sort(B,B+n,greater<int>());

	

}