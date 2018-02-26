#include <iostream>

using namespace std;

int main(){
	int n;
	int i=1;
	cin>>n;
	int count=0;
	int sum=0;

	while(sum<=n){
        sum=sum+(i*(i+1))/2;
        i++;
        count++;
	}
	cout<<count-1<<endl;
}
