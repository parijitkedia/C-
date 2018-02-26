#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int m;
	cin>>m;
	int b[m];

	int i,j;
	for(i=0;i<m;i++){
		cin>>b[i];
	}

	int n;
	cin>>n;
	int g[n];
	for(i=0;i<n;i++){
		cin>>g[i];
	}

	sort(b,b+m);
	sort(g,g+n);
    int ctr=0;
	i=0,j=0;
	while(i<m && j<n){
		if(abs(b[i]-g[j])<2){
			ctr++;
			i++;
			j++;
		}else if(b[i]<g[j]){
			i++;
		}else{
			j++;
		}
	}
	cout<<ctr<<endl;
}
