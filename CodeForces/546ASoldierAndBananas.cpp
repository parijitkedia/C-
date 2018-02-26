#include <iostream>

using namespace std;

int main(){

	int k,n,w;
	cin>>k>>n>>w;
	int cost=0;
	int i;
	for(i=1;i<=w;i++){
		cost+=k*i;
	}

	if(cost<=n)
        cout<<0<<endl;
    else
        cout<<cost-n<<endl;

}
