#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	int i,sum=0;
	while(t--){
		sum=0;
		long long int arr[26];
		long long int res[123];
		for(i=0;i<26;i++){
			cin>>arr[i];
		}

		for(i=0;i<123;i++){
			res[i]=0;
		}

		string str;
		cin>>str;

		for(i=0;i<str.size();i++){
			res[(int)str[i]]=1;
		}

		for(i=97;i<123;i++){
			if(res[i]==0){
				sum+=arr[i-97];
			}
		}
		cout<<sum<<endl;
	}
}
