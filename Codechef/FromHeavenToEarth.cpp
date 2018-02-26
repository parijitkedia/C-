#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,v1,v2;
		cin>>n>>v1>>v2;

		double ans2 = 2.0*n/v2;

		double ans1 = sqrt(2)*n/v1;
		if(ans1<ans2)
			cout<<"Stairs"<<endl;
		else
			cout<<"Elevator"<<endl;
	}
}
