#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string a,b;
		cin>>a>>b;

		vector<int> a1(123,0);
		vector<int> b1(123,0);

		int i;
		for(i=0;i<a.size();i++){
			a1[(int)a[i]]++;
		}

		for(i=0;i<b.size();i++){
			b1[(int)b[i]]++;
		}

		int maxv = max(a.size(),b.size());
		int sum=0;
		for(i=30;i<123;i++){
			sum+=min(a1[i],b1[i]);
		}
		cout<<sum<<endl;
	}
}
