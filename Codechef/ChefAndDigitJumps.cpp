#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	cin>>str;
	if(str[0]==str[str.size()-1]){
		cout<<1<<endl;
	}else{
		int i;
		int a;
		int ctr=0;
		do{
			a = str.find(str[str.size()-1]);
			cout<<"asd "<<a<<endl;
			ctr++;
			str=str.substr(0,a);
		}while(a!=0);

		cout<<ctr<<endl;
	}
}
