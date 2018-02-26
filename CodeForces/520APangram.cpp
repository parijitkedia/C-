#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){

	int n;
	cin>>n;
	string word;
	cin>>word;
    int i;
	set<int> arr;
	for(i=0;i<n;i++)
		arr.insert(tolower(word[i]));

	if(arr.size()==26)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}
