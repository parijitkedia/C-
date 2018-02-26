#include <iostream>

using namespace std;

int checkcom(int a,int b){

	int i;
	int flag=0;
	for(i=2;i<a;i++){
		if(a%i==0){
			flag++;
			break;
		}
	}

	for(i=2;i<b;i++){
		if(b%i==0){
			flag++;
			break;
		}
	}
	return flag;
}

int main(){
	int n;
	cin>>n;

	int i,j;
	int c;
	int a,b;

	for(i=4;i<n;i++){
		for(j=4;j<n;j++){
			if((i+j)==n){
				c = checkcom(i,j);
				a=i;
				b=j;
				if(c>=2)
					break;
			}
			if(c>=2)
                break;
		}
		if(c>=2)
			break;
	}

	cout<<a<<" "<<b<<endl;
	c=0;
}
