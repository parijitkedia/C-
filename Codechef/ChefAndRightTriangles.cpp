#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	int ctr=0;
	while(t--){
		int x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		int d1,d2,d3,longest;

		d1=(x2-x1)^2+(y2-y1)^2;
		d2=(x3-x2)^2+(y3-y2)^2;
		d3=(x3-x1)^2+(y3-y1)^2;

		if(d1+d2==d3 || d2+d3==d1 || d1+d3==d2)
			ctr++;
	}
	cout<<ctr<<endl;
}
