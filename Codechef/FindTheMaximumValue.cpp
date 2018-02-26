#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
    int i;
	while(t--){
		string str;
		cin>>str;

		int l = str.size();
		string num;
		for(i=0;i<l;i++){
		    cout<<str[i]<<endl;
			if(str[i]-'0'==l-1){
				cout<<"str"<<str[i]<<endl;
				num=str[i];
				break;
			}
		}
    cout<<num<<endl;
		//str.erase(std::remove(str.begin(),str.end(),num),str.end());
		cout<<str<<endl;
		//int a = stoi(str);


	}
}
