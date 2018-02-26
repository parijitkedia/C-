#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int x1,y1,x2,y2;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2 || y1==y2){
			if(x1==x2){
				if(y1>y2)
					cout<<"down"<<endl;
				if(y2>y1)
					cout<<"up"<<endl;
			}
			if(y1==y2){
				if(x2>x1)
					cout<<"right"<<endl;
				if(x1>x2)
					cout<<"left"<<endl;
			}
		}
		else{
			cout<<"sad"<<endl;
		}
	}
}
