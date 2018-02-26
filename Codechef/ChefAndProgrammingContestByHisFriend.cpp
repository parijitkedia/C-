#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli palindrome_func(vector<lli> arr,lli i,lli j){

/*	vector<lli> temp;
	lli k;
	lli a=0,ctr=0;
	for(k=j;k>=i;k--){
		temp.push_back(arr[k]);
		//temp[a]=arr[k];
		//a++;
	}
	lli b=i;
	*/
/*	for(k=0;k<j-i+1;k++)
		cout<<temp[k]<<" ";
	cout<<endl; */

	/*for(k=0;k<j-i+1;k++){
		if(temp[k]==arr[b]){
			b++;
			ctr++;
		}
	}
	//cout<<i<<" "<<j<<" "<<j-i+1<<endl;
	//cout<<"asd "<<ctr<<" "<<j-i+1<<endl;
	if(ctr==j-i+1)
		return 1;
	else
		return 0; */

	string str;
    lli k;
	for(k=i;k<=j;k++){
		str+=to_string(arr[k]);
	}
	string str1=str;
	reverse(str.begin(),str.end());

	if(!str.compare(str1))
		return 1;
	else
		return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;

	while(t--){

		lli n,k;
		vector<lli> arr;
		cin>>n>>k;
		lli i,j;
		lli p;
		lli q;
		for(i=0;i<n;i++){
			arr.push_back(0);
		}

        //cout<<str<<endl;
		for(i=0;i<k;i++){
			cin>>p>>q;
			arr[p-1]=q;
		//	cout<<"asd"<<endl;
		}

		lli ctr=0;
		lli pa=0;
		for(i=0;i<n-1;i++){
			for(j=i+2;j<n;j+=2){

				pa = palindrome_func(arr,i,j);

		//		cout<<p<<" "<<e<<endl;
				if(pa==1){
					ctr++;
				}
			}
		}
		cout<<ctr+n<<endl;
	}
}
