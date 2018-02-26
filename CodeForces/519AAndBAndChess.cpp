#include <iostream>

using namespace std;

int main(){
	char arr[8][8];
	int i,j;
	int white=0,black=0;

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='Q')
				white+=9;
			if(arr[i][j]=='R')
				white+=5;
			if(arr[i][j]=='B')
				white+=3;
			if(arr[i][j]=='N')
				white+=3;
			if(arr[i][j]=='P')
				white+=1;

			if(arr[i][j]=='q')
				black+=9;
			if(arr[i][j]=='r')
				black+=5;
			if(arr[i][j]=='b')
				black+=3;
			if(arr[i][j]=='n')
				black+=3;
			if(arr[i][j]=='p')
				black+=1;
		}
	}

	if(white>black)
		cout<<"White"<<endl;
	else if(black>white)
		cout<<"Black"<<endl;
	else
		cout<<"Draw"<<endl;
}