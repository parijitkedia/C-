#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	int i;

	vector<int> arr;
	int sum=0;
	int ctr=0;
	for(i=0;i<str.size();i++){
		if(str[i]=='B' && (str[i+1]!='W' || str[i+1]!='\0')){
			ctr++;
		}else{
			arr.push_back(ctr);
			ctr=0;
			sum++;
		}
	}
	cout<<sum<<endl;
	for(i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
