#include <iostream>

using namespace std;

int main(){
	int n,a;
	cin>>n>>a;
	int i;
	int count=0;
	int max=a,min=a;

	for(i=1;i<n;i++){
		cin>>a;
		if(a>max){
			max=a;
			count++;
		}
		if(a<min){
			min=a;
			count++;
		}
	}
	cout<<count<<endl;
}
