#include <iostream>

using namespace std;

int sumv(int a){

	return a*(a+1)/2;
}

int main(){
	int t;
	int d,n;
    int ans;
	cin>>t;
	while(t--){
        cin>>d>>n;
		while(d--){
			n=sumv(n);
		}
		cout<<n<<endl;
		ans=0;
	}
}
