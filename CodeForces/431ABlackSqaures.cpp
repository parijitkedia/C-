#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int arr[4];
	int i,j;

	for(i=0;i<4;i++){
		cin>>arr[i];
	}
	int sum=0;
	string str;
	cin>>str;
	for(i=0;i<str.size();i++){
		if(str[i]-'0'==1){
			sum+=arr[0];
		}
		if(str[i]-'0'==2){
			sum+=arr[1];
		}
		if(str[i]-'0'==3){
			sum+=arr[2];
		}
		if(str[i]-'0'==4){
			sum+=arr[3];
		}

	}
	cout<<sum<<endl;
}
