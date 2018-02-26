#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	while(true){
		cin>>n;
		if(n==0)
			break;
		int arr[n];
		int i,j,k;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
        int ans=0,flag=1;

        for(i=n-1;i>1;i--){
            j=0,k=i-1;
            while(j<k){
                if(arr[i]>(arr[j]+arr[k])){
                    ans=k-j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        cout<<ans<<endl;
    }
}
