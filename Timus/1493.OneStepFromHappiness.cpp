#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	cin>>str;
	cout<<<<endl;
	int prev = stoi(str)-1;
	int next = stoi(str)+1;
	int curr = stoi(str);

	string prev1 = to_string(prev);
	string next1 = to_string(next);
    cout<<prev1<<" "<<next1<<endl;
	int sum1=0,sum2=0;
	int i;

	for(i=0;i<3;i++){
		sum1+=prev1[i]-'0';
		sum2+=next1[i]-'0';
	}
	cout<<sum1<<" "<<sum2<<endl;
	for(i=3;i<6;i++){
		sum1-=prev1[i]-'0';
		sum2-=next1[i]-'0';
	}

	if(abs(sum1)==0 || abs(sum2)==0 )
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}
