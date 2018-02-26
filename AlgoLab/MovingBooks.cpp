#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	std::ios_base::sync_with_stdio(false) 

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> friends(n);
		vector<int> boxes(m);

		for(i=0;i<n;i++){
			cin>>friends[i];
		}

		for(i=0;i<m;i++){
			cin>>boxes[i];
		}

		int maxf,maxb;
		for(i=0;i<n;i++){
			maxf=max(maxf,friends[i]);
		}

		for(i=0;i<m;i++){
			maxb=max(maxb,boxes[i]);
		}

		if(maxb>maxf){
			cout<<"Impossible"<<endl;
		}else{
			sort(friends.rbegin(),friends.rend());
			sort(boxes.rbegin(),boxes.rend());
			
		}
	}
}