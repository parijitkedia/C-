#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

struct wizard{
	int length;
	int pos;
};

bool operator < (const wizard& w1, const wizard& w2) {
	return w1.pos < w2.pos;
}

int solve(vector<wizard>& ws,int n){

	int ctr=0;
	int secright=INT_MIN;
	int right = INT_MIN;
	
	sort(ws.begin(),ws.end());

	for(auto i=ws.begin();i<ws.end();i++){
		if(i->pos>=right){
			secright = right;
			right=max(i->pos,right+i->length);
			ctr++;
		}else{
			int f = max(i->pos,secright+i->length);
			if(f<=right){
				right = f;
			}
		}
	}
	return ctr;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i;

		vector<wizard> ws;
		for(i=0;i<n;i++){
			wizard w;
			cin>>w.length;
			cin>>w.pos;
			ws.push_back(w);
		}
		cout<<solve(ws,n)<<endl;
	}
}
