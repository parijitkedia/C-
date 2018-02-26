#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct boats{
	int length;
	int pos;
};

int solve(vector<boats>& ws){
	
	int count=0;
	int right=-1;secright=-1;

	sort(ws.begin(),ws.end());
	
	for(auto i=ws.begin();i<ws.end();i++){
		if(i->length>-)
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i,j;

		vector<boats> wizards;
		for(i=0;i<n;i++){
			boats b;
			cin>>b.length;
			cin>>b.pos;
			wizards.push_back(b);
		}
		cout<<solve(wizards)<<endl;
	}
}
