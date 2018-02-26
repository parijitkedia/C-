#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s;
	cin>>s;
	unsigned long int ctr=0;
	if(s.find("ABC")!=-1){
	//	cout<<"ABC"<<s.find("ABC")<<endl;
		ctr++;
	}

	if(s.find("ACB")!=-1){
	//	cout<<"ACB"<<s.find("ACB")<<endl;
		ctr++;
	}
	if(s.find("BAC")!=-1){
	//	cout<<"BAC"<<s.find("BAC")<<endl;
		ctr++;
	}
	if(s.find("BCA")!=-1){
	//	cout<<"BCA"<<s.find("BCA")<<endl;
		ctr++;
	}
	if(s.find("CAB")!=-1){
	//	cout<<"CAB"<<s.find("CAB")<<endl;
		ctr++;
	}
	if(s.find("CBA")!=-1){
	//	cout<<"CBA"<<s.find("CBA")<<endl;
		ctr++;
	}
	cout<<ctr<<endl;

}
