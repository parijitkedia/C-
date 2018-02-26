#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	char a[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	while(t--){
		int k;
		cin>>k;
		
		int x = k%25;
		int y=k/25;
		int i;
		if(x!=0)
			for(i=x;i>=0;i--){
				cout<<a[i];
			}
			while(y--){
				for(i=25;i>=0;i--){
					cout<<a[i];
				}
			}
			cout<<endl;
	}
}
