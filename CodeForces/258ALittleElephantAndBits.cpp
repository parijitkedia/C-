#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	cin>>str;

	int a = str.find('0');
		
	if(a!=-1){
		str.erase(a,1);
	}else{
		str.erase(1,1);
	}
	cout<<str<<endl;
}