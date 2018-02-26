#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	string n;
	cin>>n;
	int i;
	int val[n.length()];

	for(i=0;i<n.length();i++){
		val[i]=n[i]-'\0'-48;
	}
	i=0;
	if(val[i]==9){
		i++;
	}

	for(;i<n.length();i++){
		val[i]=min(val[i],9-val[i]);
	}
	for(i=0;i<n.length();i++){
		cout<<val[i];
	}
	cout<<endl;
}
