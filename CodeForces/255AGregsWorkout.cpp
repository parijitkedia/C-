#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int a;
	int i;
	int ch=0,bi=0,ba=0;
	for(i=1;i<=n;i++){
		cin>>a;
		if(i%3==1){
			ch+=a;
		}
		else if(i%3==2){
			bi+=a;
		}
		else{
			ba+=a;
		}
	}
	if(ch>bi && ch>ba)
		cout<<"chest"<<endl;
	else if(bi>ch && bi>ba)
		cout<<"biceps"<<endl;
	else
		cout<<"back"<<endl;
}
