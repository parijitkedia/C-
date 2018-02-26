#include <iostream>
#include <string>

using namespace std;

int main(){

	string seq;
	int n,t;

	cin>>n>>t;
	cin>>seq;
	int i,j;

	for(i=0;i<t;i++){
		for(j=0;j<seq.size();j++){
			if(seq[j]=='B'){
				if(seq[j+1]=='G'){
					char temp=seq[j];
					seq[j]=seq[j+1];
					seq[j+1]=temp;
					j++;
				}
			}
		}
	}

	for(i=0;i<seq.size();i++)
		cout<<seq[i];
	cout<<endl;
}
