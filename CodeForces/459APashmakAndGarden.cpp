#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;

	int dx=abs(x2-x1);
	int dy=abs(y2-y1);

	if(dx==0)
		cout<<x1+dy<<" "<<y1<<" "<<x2+dy<<" "<<y2<<endl;
	else if(dy==0)
		cout<<x1<<" "<<y1+dx<<" "<<x2<<" "<<y2+dx<<endl;
	else if(dx==dy)
		cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
	else
		cout<<-1<<endl;
}
