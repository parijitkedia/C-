#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int i;
	int sum=0;

	for(i=0;i<n;i++){
		cin>>arr[i];
		sum=sum+arr[i];
	}
	double avg;
	avg=(float)sum/(float)n;
	cout<<fixed<<setprecision(4);
	cout<<avg<<endl;


}