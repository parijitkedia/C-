#include <iostream>
#include <vector>

typedef long long int lli;

using namespace std;

struct friends{
	lli money;
	lli factor; 
};

int main(){
	lli n,d;
	cin>>n>>d;

	vector<friends> f;
	lli i;
	for(i=0;i<n;i++){
		friends fri;
		cin>>fri.money;
		cin>>fri.factor;
		f.push_back(fri);
	}

	
}