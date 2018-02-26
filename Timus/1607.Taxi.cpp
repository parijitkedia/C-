#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	if(a<=c)
	{
		while(a<=c)
		{
			if(a+b<=c)
			{
				a=a+b;
				ans=a;
			}else {
				ans=c;
				break;
			}

			if(c-d>=a)
			{
				c=c-d;
				ans=c;
			}
			else {
				ans=a;
				break;
			}
		}
		cout<<ans<<endl;
	}
	else
		cout<<a<<endl;
}
