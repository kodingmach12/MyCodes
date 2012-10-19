#include<iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
void solver()
{
    long long n;
    cin>>n;
    if(! (n%2))
    cout<<n<<endl;
    else
        cout<<(n-1)<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t){
        solver();
        t--;
    }
return 0;
}

