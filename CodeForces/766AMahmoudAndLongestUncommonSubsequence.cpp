#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string a,b;
	cin>>a;
	cin>>b;

	int i,j;
	int arr[123],arr1[123];

	for(i=0;i<a.size();i++)
		arr[i]=0;

	for(i=0;i<a.size();i++){
		arr[(int)a[i]]++;
	}

	for(i=0;i<b.size();i++)
		arr1[i]=0;
	
	for(i=0;i<b.size();i++){
		arr1[(int)b[i]]++;
	}
}