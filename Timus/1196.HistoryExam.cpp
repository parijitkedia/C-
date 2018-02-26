#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
		
	int n;
	cin>>n;
	int i,a;

	map<int,int> val;

	for(i=0;i<n;i++){
		cin>>a;
		val[a]++;
	}

	int m,ctr=0;
	cin>>m;
	for(i=0;i<m;i++){
		cin>>a;
		if(val[a]){
			ctr++;
		}
	}
	cout<<ctr<<endl;
}
