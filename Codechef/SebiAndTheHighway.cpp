#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int s,sg,fg,d,t;
		cin>>s>>sg>>fg>>d>>t;
		double ans = 180.0*d/t + s;
		if(abs(ans-sg)<abs(ans-fg))
			cout<<"SEBI"<<endl;
		else if(abs(ans-sg)>abs(ans-fg))
			cout<<"FATHER"<<endl;
		else
			cout<<"DRAW"<<endl;
	}
}