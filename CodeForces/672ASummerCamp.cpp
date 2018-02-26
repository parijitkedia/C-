#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main(){
	string str;
	int n;
	cin>>n;
	int i;


	for(i=1;i<=1000;i++){
		ostringstream oss;
		oss<<i;
		str+=oss.str();
		//cout<<str<<endl;
	}
    cout<<str[n-1]<<endl;
}
