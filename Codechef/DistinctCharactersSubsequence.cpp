#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string str;
		cin>>str;
		int arr[125];
		int i;
		for(i=0;i<125;i++){
			arr[i]=0;
		}

		for(i=0;i<str.size();i++){
			arr[str[i]-'0']++;
		}

		int ctr=0;
		for(i=0;i<125;i++){
			if(arr[i]==1)
				ctr++;
			if(arr[i]>1)
				ctr++;
		}
		cout<<ctr<<endl;
	}
}
