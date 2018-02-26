#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	string str;
	cin>>str;

	int k;
	cin>>k;

	int arr[26];
	int i;
	int sum=0;
	for(i=0;i<26;i++){
		cin>>arr[i];
		sum+=(i+1)*arr[i];
	}
	cout<<sum<<endl;
	int val[26];
	for(i=0;i<26;i++){
		val[i]=(i+1)*arr[i];
	}

	sort(val,val+26);
	int a=0;
	for(i=25;i>25-k;i--){
		a+=(i+1)*arr[i];
	}
	cout<<a<<endl;
	cout<<sum<<endl;
}
