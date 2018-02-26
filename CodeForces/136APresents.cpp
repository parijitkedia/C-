#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	int n;
	cin>>n;
	vector<int> val(n+1);
	vector<int> res(n+1);
	int i;

    for(i=0;i<n+1;i++){
        val[i]=0;
        res[i]=0;
    }

	for(i=1;i<=n;i++)
		cin>>val[i];

	for(i=1;i<=n;i++){
		res[val[i]]=i;
	}

	for(i=1;i<=n;i++){
        if(res[i]!=0)
            cout<<res[i]<<" ";
	}

	cout<<endl;
    return 0;
}
