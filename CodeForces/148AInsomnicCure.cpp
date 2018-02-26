#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> val(5);
	int i,j;
	int count=0;

	for(i=1;i<=5;i++){
		cin>>val[i];
	}

	int arr[val[5]];

	for(i=1;i<=val[5];i++)
        arr[i]=0;

	for(i=1;i<5;i++){
		for(j=1;j<=val[5];j++){
			if(j%val[i]==0){
				arr[j]=1;
			}
		}
	}

	for(i=1;i<=val[5];i++){
		if(arr[i]==0){
			count++;
		}
	}

	cout<<val[5]-count<<endl;
}
