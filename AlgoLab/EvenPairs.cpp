#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> val(n);
		int i,j;
		int sum=0,count=0;

		for(i=0;i<n;i++)
			cin>>val[i];

		for(i=0;i<n;i++){
			sum=0;
			for(j=i;j<n;j++){
				sum+=val[j];
				if(sum%2==0)
					count++;
			}
		}
		cout<<count<<endl;
	}
}
