#include <iostream>
#include <set>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int i;
		for(i=0;i<n;i++)
			cin>>arr[i];

		set<int> st;
		for(i=0;i<n;i++)
			st.insert(arr[i]);

		cout<<st.size()<<endl;
	}
}