#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	int i;
	int l=str.size();
	long long int sum=n;

	if(n%l==0){
		for(i=1;i<n/l;i++){
			sum*=(n-(i*l));
		}
	}else{
		for(i=1;i<=n/l;i++){
			sum*=(n-(i*l));
		}
	}
	cout<<sum<<endl;
}
