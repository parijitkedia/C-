#include <iostream>
#include <cstring>

typedef long long lli lli;

using namespace std;

lli check(lli arr,lli i){

}

int main(){
	lli t;
	cin>>t;

	while(t--){
		lli n;
		cin>>n;
		lli arr[n];

		lli i;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}

		lli a,b,c;
		cin>>a>>b>>c;

		string str;
		cin>>str;

		for(i=0;i<n;i++){
			if(str[i]=='R'){
				for(j=n-1;j>=i;j--){
					
				}
			}else if(str[i]=='A'){
				for(j=1i;j<n;j++){
					arr[j]+=a;
				}
			}else if(str[i]=='M'){
				for(j=i;j<n;j++){
					arr[j]= (arr[j]*b)%c;
				}
			}
		}
	}
}