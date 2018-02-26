#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int solve(int n, vector<vector<int> >& positions){

	priority_queue<pair<int,int>, vector<pair<int,int> > > poss;
	int i,j;
	for(i=0;i<n;i++){
		int m = positions[i].size();
		for(j=0;j<m;j++){
			poss.push(make_pair(positions[i][j],i));
		}
	}

	int min_dist = INT_MAX;

	vector<int> chosen_position(n,-1);
	set<pair<int,int> > chosen;
	int ctr=0;

	while(!poss.empty()){
		pair<int,int> tuple = poss.top();
		poss.pop();

		int pos = tuple.first;
		int word = tuple.second;

		if(chosen_position[word]==-1){
			ctr++;
		}else{
			chosen.erase(make_pair(chosen_position[word],word));
		}

		chosen_position[word]=pos;
		chosen.insert(tuple);

		if(ctr==n){
			int b = (--chosen.end())->first;
			int a = chosen.begin()->first;
			int dist = b-a;
		//	cout<<b<<" "<<a<<endl;
			if(dist<min_dist){
				min_dist=dist;
			}
		}
	}
	return min_dist+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> occs(n);
		int i,j;
		for(i=0;i<n;i++){
			cin>>occs[i];
		}

		vector<vector<int> > poss(n);
		for(i=0;i<n;i++){
			poss[i]=vector<int>(occs[i]);
			for(j=0;j<occs[i];j++){
				cin>>poss[i][j];
			}
		}
		cout<<solve(n,poss)<<endl;
	}
}



/*
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<int> occs(n);
		int i,j;
		for(i=0;i<n;i++){
			cin>>occs[i];
		}
		int maxv=-1;
		vector<vector<int> > poss(n);
		for(i=0;i<n;i++){
			poss[i]=vector<int>(occs[i]);
			for(j=0;j<occs[i];j++){
				cin>>poss[i][j];
				maxv = max(maxv,poss[i][j]);
			}
		}

		vector<int> ans(maxv,0);
		for(i=0;i<n;i++){
			for(j=0;j<occs[i];j++){
				ans[poss[i][j]]=i+1;
			}
		}

        int val = n*(n+1)/2;
		i=1,j=1;
		int sum=ans[1];
		int minv=ans.size()+1;

		while(i<ans.size() && j<ans.size()){

			if(sum<val && j<ans.size()){
				j++;
				sum+=ans[j];
			}
			else{ //if(sum>val && j<ans.size()){
				sum-=ans[i];
				minv = min(minv,j-i);
				i++;
			}
			else if(sum==val){
				minv = min(minv,j-i);
				j++;
				sum+=ans[j];
			}
		}
		cout<<minv+1<<endl;
	}
}
*/
