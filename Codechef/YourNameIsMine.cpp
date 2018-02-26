#include <iostream>
#include <string>

using namespace std;

bool check(string s1,string s2){
	int j=0;
	int i;
	for(i=0;i<s2.size()&& j<s1.size();i++){
		if(s1[j]==s2[i]){
			j++;
		}
	}
	if(j==s1.size())
		return true;
	else
		return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		bool ans;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()>=s2.size())
			ans = check(s2,s1);
		else
			ans = check(s1,s2);
		if(ans==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
