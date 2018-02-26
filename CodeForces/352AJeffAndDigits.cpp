#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int i,a;
	int zero=0,five=0;
	for(i=0;i<n;i++){
		cin>>a;
		if(a==0){
			zero++;
		}else{
			five++;
		}
	}
    if(zero==0){
    	cout<<-1<<endl;
    }else{
    	for(i=(five/9)*9;;i--){
    		cout<<5;
    	}
    	for()
    }
}
