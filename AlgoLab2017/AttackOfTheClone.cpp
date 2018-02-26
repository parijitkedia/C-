#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
	return a.second<b.second;
}

inline int check(vector<pair<int,int> >& arr, int amin,int bmax){
	int a=amin;
	int n=0;
	for(auto it=arr.begin();it!=arr.end();it++){
		if(it->first > a && it->second < bmax){
			a=it->second;
			n++;
		}
	}
	return n;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		vector<pair<int,int> > arr(n);
		map<int,int> ctr;
		int i;
		for(i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			arr[i]=make_pair(a,b);
			ctr[a]++;
			ctr[b]--;
			if(a>b)
				ctr[0]++;
		}

		int olap=0,minv=n,k=0;
		for(auto it=ctr.begin();it!=ctr.end();it++){
			k+=it->second;
			if(k<=10 && k<minv){
				olap=it->first;
				minv=k;
			}
		}

		vector<pair<int,int> > overlap;
		vector<pair<int,int> > nooverlap;
		for(i=0;i<n;i++){
			int a = arr[i].first;
			int b = arr[i].second;
			if(a>olap)
				arr[i].first=a-olap;
			else
				arr[i].first=a-olap+m;
			if(b>olap)
				arr[i].second=b-olap;
			else
				arr[i].second=b-olap+m;

			if( (a<=b && a<=olap && olap<=b) || (a>b && (a<=olap || olap<=b) ) )
				overlap.push_back(arr[i]);
			else
				nooverlap.push_back(arr[i]);
		}

		sort(nooverlap.begin(),nooverlap.end(),comp);
		int ans = check(nooverlap,-1,m);

		for(auto it = overlap.begin();it!=overlap.end();it++){
			ans=max(ans, check(nooverlap,it->second%m,it->first)+1);
		}
		cout<<ans<<endl;
	}
}