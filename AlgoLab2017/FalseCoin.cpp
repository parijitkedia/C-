#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		vector<int> light(n,0),heavy(n,0),equal(n,0);

		int o=0;
		int i,j;
		for(i=0;i<k;i++){
			int p;
			cin>>p;

			vector<int> left(p),right(p);
			for(j=0;j<p;j++){
				int a;
				cin>>a;
				left.push_back(a);
			}

			for(j=0;j<p;j++){
				int a;
				cin>>a;
				right.push_back(a);
			}

			char ch;
			cin>>ch;

			if(ch=='='){
				for(j=0;j<p;j++){
					equal[left[j]]++;
				}
				for(j=0;j<p;j++){
					equal[right[j]]++;
				}
			}else if(ch=='>'){
				o++;
				for(j=0;j<p;j++){
					heavy[left[j]]++;
				}

				for(j=0;j<p;j++){
					light[right[j]]++;
				}

			}else if(ch=='<'){
				o++;
				for(j=0;j<p;j++){
					light[left[j]]++;
				}

				for(j=0;j<p;j++){
					heavy[right[j]]++;
				}
			}
		}
		int coin=0,ctr=0;
		for(i=0;i<n;i++){
			if(equal[i]==0 && heavy[i]==o && light[i]==0){
				coin=i;
				ctr++;
			}
			else if(equal[i]==0 && heavy[i]==0 && light[i]==o){
				coin=i;
				ctr++;
			}
		}
		if(ctr==1)
			cout<<coin<<endl;
		else
			cout<<0<<endl;
	}
}