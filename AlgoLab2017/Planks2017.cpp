#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int len(bitset<21> b; vector<int>& L){
	int length=0;
	int i;
	for(i=0;i<L.size();i++){
		if(b.test(i)){
			length+=L[i];
		}
	}
	return length;
}

vector<vector<int> > partition(int ans, vector<int>& L){
	int n=L.size();
	vector<vector<int> > partitions;
	auto all = bitset<21>((1<<n)-1);
	for(int i=0;i<(1<<n);i++){
		auto I = bitset<21>(i);
		for(int j=0;j<(1<<n);j++){
			auto J = bitset<21>(j);

			auto F1 = I & J;
			auto F2 = J & (all xor I);
			auto F3 = I & (all xir J);
			auto F4 = all xor (I | J);

			vector<int> l(4);
			l[0]=len(F1,L);
			l[1]=len(F2,L);
			l[2]=len(F3,L);
			l[3]=len(F4,L);

			if(*max_element(l.begin(),l.end()) <= ans){
				partitions.push_back(l);
			}
		}
	}
	return partitions;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> arr(n);
		int i,sum=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		int ans=sum/4;
		sort(arr.rbegin(),arr.rend());

		int n1=n/2;
		int n2=n-n1;

		vector<int> L1(n1);
		vector<int> L2(n2);

		copy(arr.begin(),arr.begin()+n1,L1.begin());
		copy(arr.begin()+n1,arr.end(),L2.begin());

		vector<vector<int> > V1 = partition(ans,L1);
		vector<vector<int> > V2 = partition(ans,L2);

		sort(V2.begin(),V2.end());

		
	}
}