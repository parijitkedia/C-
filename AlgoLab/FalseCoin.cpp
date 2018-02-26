#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int i,j;

		for(i=0;i<k;i++){
			int p;
			cin>>p;
			vector<int> arr(2*p);
			vector<int> val(2*p);

			for(i=1;i<2*p;i++)
				val[i]=0;

			for(j=1;j<=2*p;j++){
				cin>>arr[j];
			}
			char ch;
			cin>>ch;

			if(ch=='='){
				for(j=1;j<=2*p;j++){
					val[arr[j]]=1;
				}
			}

			if(ch=='<'){
				for()
			}

			if(ch=='>'){

			}
		}
	}
}