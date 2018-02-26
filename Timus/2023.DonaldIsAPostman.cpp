#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	int ctr=0;
	int i;
	int pos=1;
	for(i=0;i<n;i++){
		cin>>str;
		if((str[0]=='A' || str[0]=='P' || str[0]=='O' || str[0]=='R') && pos==2){
			pos=1;
			ctr++;
		}
		else if((str[0]=='A' || str[0]=='P' || str[0]=='O' || str[0]=='R') && pos==3){
			pos=1;
			ctr+=2;
		}
		else if((str[0]=='B' || str[0]=='M' || str[0]=='S') && pos==1){
			pos=2;
			ctr++;
		}
		else if((str[0]=='B' || str[0]=='M' || str[0]=='S') && pos==3){
			pos=2;
			ctr++;
		}
		else if((str[0]=='D' || str[0]=='G' || str[0]=='J' || str[0]=='K' || str[0]=='T' || str[0]=='W') && pos==1){
			pos=3;
			ctr+=2;
		}
		else if((str[0]=='D' || str[0]=='G' || str[0]=='J' || str[0]=='K' || str[0]=='T' || str[0]=='W') && pos==2){
			pos=3;
			ctr++;
		}
	}
	cout<<ctr<<endl;
}
