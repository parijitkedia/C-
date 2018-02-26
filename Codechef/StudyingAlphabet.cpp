#include <iostream>
#include <string>

using namespace std;

int check(string word, string s){
	int arr[125];
	int i;
	int count=0;
	for(i=0;i<125;i++)
		arr[i]=0;

	for(i=0;i<s.length();i++){
		arr[s[i]]++;
	}
	for(i=0;i<word.length();i++){
		arr[word[i]]++;
	}
	for(i=0;i<125;i++){
		if(arr[i]>0)
			count++;
	}
	if(count==s.length() || count==word.length())
		return 100;
	else
		return 101;
}

int main(){
	string str;
	cin>>str;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		string word;
		cin>>word;
		int a = check(word,str);
		if(a==100)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
