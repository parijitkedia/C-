#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main (){
    double n, m ,a ;
    cin>>n>>m>>a;
    cout<<fixed<<setprecision(0)<<ceil(n/a)*ceil(m/a)<<endl;
    return 0;
}
