#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int x;
	int i;
	int a=0,b=0,sum=0;

	for(i=0;i<n;i++){
		cin>>x;
		if(x==25)
			a++;
		if(x==50){
			b++;
			a--;
		}
		if(x==100){
			if(b!=0){
				b--;
				a--;
			}else{
				a-=3;
			}
		}
		if(a<0 || b<0)
			break;
	}
	if(a<0 || b<0){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
}
