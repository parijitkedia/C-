#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	string str;
	cin>>str;

	int i;
	int sum = min(abs(str[0]-'a'),26-abs(str[0]-'a'));
	for(i=0;i<str.size()-1;i++){
		sum+=min(abs(str[i+1]-str[i]),26-abs(str[i+1]-str[i]));
	}
	cout<<sum<<endl;
}
