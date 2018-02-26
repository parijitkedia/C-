#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	string num1;
	string num2;
	cin>>num1;
	cin>>num2;
	int count=0;
	int i;

	for(i=0;i<n;i++){
		int val = abs( num1[i] - num2[i]);
		count = count + min(val,10-val);
	}
	cout<<count<<endl;
}
