#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	string str;
	cin>>str;
	int arr[124];
	int i;
	for(i=0;i<124;i++){
		arr[i]=0;
	}
	int flag=0;
	for(i=0;i<str.size();i++){
		arr[(int)str[i]]++;
		if(arr[(int)str[i]]>k){
			flag=1;
		}
	}

	if(flag==1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}