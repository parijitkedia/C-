#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	char arr[m][2];
	int len[m][2];
	int l;
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<2;j++){
			cin>>arr[i][j];
			l=arr[i][j].size();
			len[i][j]=l;
		}
	}

	string text;
	for(i=0;i<n;i++){
		cin>>text;
		for(j=0;j<m;j++){
			if(text==arr[j][0]){
				if(len[j][0]<=len[j][1]){
					cout<<arr[j][0];
				}else{
					if(len[j][0]>len[j][1]){
						cout<<arr[j][1];
					}
				}
			}
		}
	}
}
