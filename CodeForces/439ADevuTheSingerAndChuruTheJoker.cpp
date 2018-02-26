#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,d;
	cin>>n>>d;
	vector<int> arr(n);
	int i;
	int sum=0;
	for(i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int ans=sum+10*(n-1);
	if(ans>d)
		cout<<-1<<endl;
	else
		cout<<(d-sum)/5<<endl;
}