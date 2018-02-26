#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int i,j;
		int count=0;
		for(i=a;i<=b;i++){
			for(j=c;j<=d;j++){
				if(i<j)
					count++;
			}
		}
		cout<<count<<endl;
		count=0;
	}
}