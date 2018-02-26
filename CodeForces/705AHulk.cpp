#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	string ans;

	int i;
	ans="I hate ";
	for(i=2;i<=n;i++){
		if(i%2==0){
			ans=ans+"that I love ";
		}else{
			ans=ans+"that I hate ";
		}
	}
	ans=ans+"it";
	cout<<ans<<endl;
}
