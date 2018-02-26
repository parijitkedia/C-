#include <iostream>
#include <stack>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		string str;
		cin>>str;
		int i,l=str.size();
		stack<char> st;

		st.push(str[0]);
		int ctr=0;

		for(i=1;i<l;i++){
			if(!st.empty()){
				if(str[i]=='>' && st.top()=='<'){
            //        cout<<"1"<<endl;
					ctr+=2;
					st.pop();
				}
			}
			else{
			//	cout<<"2"<<endl;
				st.push(str[i]);
			}
		}
		cout<<ctr<<endl;

	}

}
