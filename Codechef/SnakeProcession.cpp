#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int r;
	cin>>r;
	int l;
	string str;
	int i,k,flag;
	int h,t;
	while(r--){
		h=0,t=0,k=0,flag=0;
		cin>>l;
		cin>>str;
		//str.erase(std::remove(str.begin(),str.end(),'.'),str.end());

		for(i=0;i<str.size();i++){
			if(str[i]=='H')
				h++;
			if(str[i]=='T')
				t++;
		}
		//cout<<h<<" "<<t<<endl;
		if(h!=t)
			cout<<"Invalid"<<endl;
		else{
			for(i=0;i<str.size();i++){
				int a = str.find('H',i);
				int b = str.find('T',i);

				//cout<<a<<" "<<b<<" "<<i<<" "<<k<<endl;
				if( (a==-1 && b!=-1) || (a!=-1 && b==-1) || a>b){
					flag=1;
					break;
				}else if(a==-1 && b==-1){
					flag=0;
					break;
				}else{
					i=b;
					//k=b+1;
				}
			}
			if(flag==1)
				cout<<"Invalid"<<endl;
			else
				cout<<"Valid"<<endl;
		}
	}
}
