#include <iostream>

using namespace std;

int main(){
	int n,m;

	cin>>n>>m;

    int i,val;
	int pos=1;
	long long ans=0;

	for(i=0;i<m;i++){
        cin>>val;
		ans += (val-pos+n)%n;
		pos=val;
	}
	cout<<ans<<endl;
}
