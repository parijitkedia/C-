#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int i;
		string str;
		int c=0,s=0,e=0,em=0,m=0,mh=0,h=0;
		for(i=0;i<n;i++){
			cin>>str;
			if(!str.compare("cakewalk"))
				c++;
			if(!str.compare("simple"))
				s++;
			if(!str.compare("easy"))
				e++;
			if(!str.compare("easy-medium"))
				em++;
			if(!str.compare("medium"))
				m++;
			if(!str.compare("medium-hard"))
				mh++;
			if(!str.compare("hard"))
				h++;
		}
		//cout<<c<<" "<<s<<" "<<e<<" "<<m<<" "<<h<<endl;
		if(c>=1 && s>=1 && e>=1){
			if( (em>=1 || m>=1) && (mh>=1 || h>=1) ){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}
}
