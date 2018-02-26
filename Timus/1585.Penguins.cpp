#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
    cin.sync();
    cin.ignore();
	int i,j;
	string str;
	int m,e,l;
	for(i=0;i<n;i++){
		getline(cin,str);
		cin.sync();
		if(!str.compare("Emperor Penguin"))
			e++;
		else if(!str.compare("Macaroni Penguin"))
			m++;
		else if(!str.compare("Little Penguin"))
			l++;
	}
	int ans = max(m,max(e,l));
	if(ans==e)
		cout<<"Emperor Penguin"<<endl;
	else if(ans==m)
		cout<<"Macaroni Penguin"<<endl;
	else
		cout<<"Little Penguin"<<endl;
}
