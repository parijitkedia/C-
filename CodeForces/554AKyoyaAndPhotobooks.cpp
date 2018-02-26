#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	cin>>str;

	cout<<(str.size()+1)*26 - str.size()<<endl;
}