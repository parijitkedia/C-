#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	int arr[124];

	int i;
	for(i=0;i<124;i++){
		arr[i]=0;
	}

	for(i=0;i<str.size();i++){
		arr[(int)str[i]]++;
	}

	int ctr=0,flag=0;
	for(i=0;i<124;i++){
		if(arr[i]>26){
			flag=1;
			break;
		}
		if(arr[i]>1){
			ctr+=arr[i]-1;
		}
	}
	if(flag==1)
		cout<<-1<<endl;
	else
		cout<<ctr<<endl;
}