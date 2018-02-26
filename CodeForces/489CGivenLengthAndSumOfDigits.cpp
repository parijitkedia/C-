#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	int n,s,n1,s1;
	cin>>n>>s;
	n1=n,s1=s;
	if(s==0){
		if(n<=1){
			cout<<0<<" ";
		}else{
			cout<<-1<<" ";
		}
	}
	else if(s>9*n){
		cout<<-1<<" ";
	}else{
		s-=1;
		int res[n];
		int i;
		for(i=n-1;i>0;i--){
			if(s>=9){
				res[i]=9;
				s-=9;
			}else{
				res[i]=s;
				s=0;
			}
		}
		res[0]=s+1;
		for(i=0;i<n;i++){
			cout<<res[i];
		}
		cout<<" ";
	}

	n=n1,s=s1;
	if(s==0){
		if(n<=1){
			cout<<0<<" ";
		}else{
			cout<<-1<<" ";
		}
	}
	else if(s>9*n){
		cout<<-1<<" ";
	}
	else{
		
		int res[n];
		int i;

		for(i=0;i<n;i++){
			if(s>=9){
				res[i]=9;
				s-=9;
			}else{
				res[i]=s;
				s=0;
			}
		}
		for(i=0;i<n;i++){
			cout<<res[i];
		}
		cout<<" ";
	}
	cout<<endl;
}
