#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string word;
		cin>>word;
		int l=word.length();
		int i;
		int arr[127],arr1[127];
		int flag=0;
		for(i=0;i<127;i++){
			arr[i]=0;
			arr1[i]=0;
		}
		int count=0;
		if(l%2==0){
			int h=l/2;
			for(i=0;i<h;i++){
				arr[(int)word[i]]++;
			}
			for(i=h;i<l;i++){
				arr1[(int)word[i]]++;
			}

			for(i=0;i<127;i++){
				if(arr[i]==arr1[i])
					continue;
				else{
					flag=1;
					break;
				}
			}

			if(flag==1)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}else{
			int h=l/2;
			for(i=0;i<h;i++){
				arr[(int)word[i]]++;
			}
			for(i=h+1;i<l;i++){
				arr1[(int)word[i]]++;
			}
			for(i=0;i<127;i++){
				if(arr[i]==arr1[i])
					continue;
				else{
					flag=1;
					break;
				}
			}
			if(flag==1)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	}
}
