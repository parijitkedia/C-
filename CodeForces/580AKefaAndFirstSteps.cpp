#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> val(n);
	int i;
	int a=0,b=0,count=0;

	for(i=0;i<n;i++){
		cin>>val[i];
	}

	for(i=0;i<n;i++){
		if(val[i]>=a)
			count++;
		else
			count=1;
		if(count>=b)
			b=count;
		a=val[i];
	}
	cout<<b<<endl;
}
