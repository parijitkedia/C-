#include <iostream>

using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	if(a*d == b*c){
		cout<<"Possible"<<endl;
	}else if(a*b==c*d){
		cout<<"Possible"<<endl;
	}else if(a*c==b*d){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
}