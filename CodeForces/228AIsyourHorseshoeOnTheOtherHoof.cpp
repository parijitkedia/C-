#include <iostream>
#include <set>

using namespace std;

int main(){
	set<int> arr;
	long long a;
	int i;
	for(i=0;i<4;i++){
		cin>>a;
		arr.insert(a);
	}
	cout<<4-arr.size()<<endl;
}
