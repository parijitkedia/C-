#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int l,b;
    int limsum,bobsum,pos;
	int i,k;
	while(t--){
		k=1;
		limsum=0,bobsum=0;
		cin>>l>>b;
		for(;;){
			if(k%2==0){
				bobsum+=k;
			}
			if(k%2==1){
				limsum+=k;
			}
			k++;
			if(limsum>l || bobsum>b){
				pos=k;
				break;
			}
		}
		if(pos%2==0)
			cout<<"Bob"<<endl;
		else
			cout<<"Limak"<<endl;
	}
}
