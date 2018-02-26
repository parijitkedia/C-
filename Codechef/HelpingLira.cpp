#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	int x1,y1,x2,y2,x3,y3;
	double area,maxv=0,minv=10000000;
	for(i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		area  = 0.5 * abs((x1 * y2 - x2 * y1) + (x2 * y3 - x3 * y2) + (x3 * y1 - x3 * y1));
		if(area>=maxv)
			maxv=area;
		if(area<minv)
			minv=area;
	}
	cout<<maxv<<" "<<minv<<endl;

}
