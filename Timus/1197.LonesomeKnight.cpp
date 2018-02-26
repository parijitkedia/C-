#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;;
	cin>>n;
	int arr[8][8]={2,3,4,4,4,4,3,2,
             3,4,6,6,6,6,4,3,
             4,6,8,8,8,8,6,4,
             4,6,8,8,8,8,6,4,
             4,6,8,8,8,8,6,4,
             4,6,8,8,8,8,6,4,
             3,4,6,6,6,6,4,3,
             2,3,4,4,4,4,3,2};

	while(n--){
		string str;
		cin>>str;
		char a = str[0];
		int num = str[1]-'0';
		int pos = a-'a';
		cout<<arr[pos][num-1]<<endl;

	}
}
