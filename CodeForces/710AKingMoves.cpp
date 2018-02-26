#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int arr[8][8]={{3,5,5,5,5,5,5,3},
				   {5,8,8,8,8,8,8,5},
				   {5,8,8,8,8,8,8,5},
				   {5,8,8,8,8,8,8,5},
				   {5,8,8,8,8,8,8,5},
				   {5,8,8,8,8,8,8,5},
				   {5,8,8,8,8,8,8,5},
				   {3,5,5,5,5,5,5,3}};

	char ch;
	int a;
	cin>>ch>>a;

	cout<<arr[(int)ch-97][a-1]<<endl;
}
