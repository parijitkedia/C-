#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		if(n==0){
			cout<<0<<endl;
		}else if(n==1){
			cout<<2<<endl;
		}else{
			arr[0]=0;
			arr[1]=2;
			int i;
			if(n>=2){
				for(i=2;i<=n;i++){
					arr[i]=i+arr[i-1]+1;
				}
			}
			cout<<arr[n]<<endl;
		}
		
	}
}

