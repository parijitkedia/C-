#include <iostream>
#include <string>

using namespace std;

int check(int num){

	int i;
	int arr[10];
	int count=0;

	for(i=0;i<10;i++)
		arr[i]=0;

	for(i=num;i>0;i=i/10){
		int digit=i%10;
		arr[digit]++;
	}

	for(i=0;i<10;i++){
		if(arr[i]==1)
			count++;
	}

	if(count==4)
		return 1;
	else
		return 0;
}

int main(){

	int year;
	cin>>year;
	int i;
	for(i=year+1;i<=9012;i++){
		int val = check(i);
		if(val==1){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

