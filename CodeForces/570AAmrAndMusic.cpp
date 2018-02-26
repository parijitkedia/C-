#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int i,j;
	int res[n],arr[n];

	for(i=0;i<n;i++){
        cin>>arr[i];
	}

	for(i=0;i<n;i++){
		res[i]=i;
	}
    int sum=0;

	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp1 = arr[j];
				int temp2 = res[j];
				arr[j]=arr[j+1];
				res[j]=res[j+1];
				arr[j+1]=temp1;
				res[j+1]=temp2;
			}
		}
	}

	for(i=0;i<n;i++){
		sum+=arr[i];
		if(sum<=k){
			continue;
		}else
			break;
	}
	cout<<i<<endl;
    for(j=0;j<i;j++){
        cout<<res[j]+1<<" ";
    }
    cout<<endl;
}
