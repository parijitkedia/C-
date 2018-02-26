#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	std::getline(std::cin,str);
	int i,ctr=0;
	for(i=0;i<str.size();i++){
		if (str[i] == 'a' || str[i] == 'd' || str[i] == 'g' || str[i] == 'j' || str[i]== 'm' || str[i] == 'p' || str[i] == 's'
		 || str[i]== 'v' || str[i] == 'y' || str[i]== '.' || str[i]== ' ' || str[i]=='_'){
			ctr++;
		}
		if (str[i] == 'b' || str[i] == 'e' || str[i] == 'h' || str[i] == 'k' || str[i]== 'n' || str[i] == 'q' || str[i] == 't'
		 || str[i]== 'w' || str[i] == 'z' || str[i]== ','){
			ctr+=2;
		}
		if (str[i] == 'c' || str[i] == 'f' || str[i] == 'i' || str[i] == 'l' || str[i]== 'o' || str[i] == 'r' || str[i] == 'u'
		 || str[i]== 'x' || str[i] == '!'){
			ctr+=3;
		}
	}
	cout<<ctr<<endl;
}
