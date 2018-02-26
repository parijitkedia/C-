#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n][2];
	int i,j;
	int chris=0,mishka=0;
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		if(arr[i][0]>arr[i][1])
			mishka++;
		else if(arr[i][0]<arr[i][1])
			chris++;
		else
			continue;
	}

	if(chris>mishka)
		cout<<"Chris"<<endl;
	else if(chris<mishka)
		cout<<"Mishka"<<endl;
	else
		cout<<"Friendship is magic!^^"<<endl;

}
