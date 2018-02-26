#include <iostream>
#include <string>

using namespace std;

int main(){

	string word;
	cin>>word;

	int arr[125]={0};
    int count=0;
	int i;
	for(i=0;i<word.size();i++){
		arr[(int)word[i]]++;
	}

	for(i=0;i<125;i++){
		if(arr[i]>=1)
			count++;
	}

	if(count%2==0)
		cout<<"CHAT WITH HER!"<<endl;
	else
		cout<<"IGNORE HIM!"<<endl;

	/*for(i=0;i<125;i++){
		if(arr[i]>0)
			cout<<arr[i]<<" ";
	}*/
}
