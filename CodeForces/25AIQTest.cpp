#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	int arr;
	int pos1,pos2,even=0,odd=0;
	for(i=0;i<n;i++){
		cin>>arr;
		if(arr%2==0){
			even++;
			pos1=i+1;
		}
		else{
			odd++;
			pos2=i+1;
		}
	}
	if(even==1)
		cout<<pos1<<endl;
	else
		cout<<pos2<<endl;
}
