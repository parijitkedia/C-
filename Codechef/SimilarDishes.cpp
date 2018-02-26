#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	int i,j,ctr=0;
	while(t--){
		ctr=0;
		char a[4][10];
		char b[4][10];
		for(i=0;i<4;i++){
			cin>>a[i];
		}
		for(i=0;i<4;i++){
			cin>>b[i];
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(strcmp(a[i],b[j])==0){
					ctr++;
					break;
				}
			}
		}
		cout<<ctr<<endl;
		
		if(ctr>=2)
			cout<<"similar"<<endl;
		else
			cout<<"dissimilar"<<endl;
	}
}
