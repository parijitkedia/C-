#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	queue <int> arr;
	queue <int> pos;
	int i;
	for(i=0;i<n;i++){
		pos.push(i+1);
		int a;
		cin>>a;
		arr.push(a);
	}
	i=0;
	if(arr.size()==1){
		cout<<pos.front()<<endl;
	}else{
		do{
			int a;
			a = arr.front();
			if(a<=m){
				arr.pop();
				pos.pop();
			}else{
				int b;
				b = a - m;
				arr.pop();
				arr.push(b);

				int c = pos.front();
				pos.pop();
				pos.push(c);
			}
		}while(arr.size()>1);
		cout<<pos.front()<<endl;
	}	
}
