#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string n;
		cin>>n;
		int i;
		int count=0;
		for(i=0;i<n.length();i++){
			if(n[i]=='4' || n[i]=='7')
				continue;
            else
                count++;
		}
		cout<<count<<endl;
	}
}
