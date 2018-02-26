#include <iostream>
#include <cmath>

using namespace std;

int sod(int num){
	int i;
	int dig,sum=0;
	for(i=num;i>0;i=i/10){
		dig=i%10;
		sum+=dig;
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	int ctr=0;
    int i;
	for(i=max(n-97,1);i<=n;i++){
		int ans = i + sod(i) + sod(sod(i));
		if(ans==n)
			ctr++;
	}
	cout<<ctr<<endl;

}
