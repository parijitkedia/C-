#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
	int n,k;
	cin>>k>>n;
	int i,j;
	string *arr=new string[k];
	for(i=0;i<k;i++){
		cin>>arr[i];
	}
	int flag=0;
	string num;
	for(i=0;i<n;i++){
		flag=0;
		cin>>num;
		if(num.length()>=47){
			flag=1;
		}else{
			for(j=0;j<k;j++){
				if(num.find(arr[j])!=string::npos){
					flag=1;
					break;
				}
			}
		}
		
		if(flag==1)
			cout<<"Good"<<endl;
		else
			cout<<"Bad"<<endl;
	}
}
