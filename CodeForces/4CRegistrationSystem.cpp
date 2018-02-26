#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string val;
    map<string, int> arr;
    int i;
    for(i=0;i<n;i++){
        cin>>val;
        if(arr[val]>0)
            cout<<val<<arr[val]<<endl;
        else
            cout<<"OK"<<endl;
        arr[val]++;
    }
}
