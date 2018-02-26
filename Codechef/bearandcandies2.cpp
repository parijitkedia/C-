#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int A,B;
		cin>>A>>B;
		int z,y,j,L;
		z=0;
		L=0;
		j=2;
		y=0;
		do
		{
			z=z+1;
			L=z*z;
			if (L>A){
				cout<<"Bob"<<endl;
				break;
			}

			else{
				y=y+j;
				j=j+2;
				if (y>B){
					cout<<"Limak"<<endl;
					break;
				}

			}

		}while(L<=A || y<=B);
	}
}
