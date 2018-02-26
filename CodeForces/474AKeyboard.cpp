#include <iostream>
#include <cstring>

using namespace std;

int main(){

	string a[10] = {"q","w","e","r","t","y","u","i","o","p"};
	string b[10] = {"a","s","d","f","g","h","j","k","l",";"};
	string c[10] = {"z","x","c","v","b","n","m",",",".","/"};

	string str;
	cin>>str;
	int pos;
	if(str[0]=='R')
		pos=-1;
	else
		pos=1;

	string s,newstr;
	getline(cin,s);
	int i,j;
	for(i=0;i<s.size();i++){
		for(j=0;j<10;j++){
			if(a[j][0]==s[i]){
				newstr = newstr + a[i]+pos;
			}
			else if(b[j][0]==s[i]){
				newstr = newstr + b[i]+pos;
			}else if(c[j][0]==s[i]){
				newstr = newstr + c[i]+pos;
			}
		}
	}
	cout<<newstr<<endl;
}
