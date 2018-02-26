#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int i,ctr=0;
	int num;
	int arr[n];

	for(i=1;i<=n;i++)
		arr[i]=0;

	while(k--){
		string s;
		cin>>s;
		if(s=="CLOSEALL"){
			cout<<0<<endl;
			ctr=0;
			for(i=1;i<=n;i++)
				arr[i]=0;
		}else{
			cin>>num;
			if(arr[num]==0){
				arr[num]=1;
				ctr++;
				cout<<ctr<<endl;
			}else{
				arr[num]=0;
				ctr--;
				cout<<ctr<<endl;
			}
		}
	}
}