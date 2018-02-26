#include <iostream>
#include <set>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	int i;
	while(t--){
		cin>>n;
		int arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i];

		set<int> st;
		for(i=0;i<n;i++)
			st.insert(arr[i]);

		cout<<st.size()<<endl;
	}
}
