#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long int lli;
using namespace std;

int main(){
	lli n;
	cin>>n;

	vector<lli> arr;
	lli i,j,k;
	for(i=0;i<n;i++){
		lli a;
		cin>>a;
		arr.push_back(a);
	}

	sort(arr.begin(),arr.end());
	lli ctr=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if(arr[i]==1){
					ctr++;
				}
				else if(__gcd(arr[i],__gcd(arr[j],arr[k]))==1){
					ctr++;
				}
			}
		}
	}
	cout<<ctr<<endl;
}
