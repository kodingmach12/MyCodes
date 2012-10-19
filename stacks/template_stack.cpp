#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stackwithMin A;
    int k,n;
    cin>>k;
    while(k)
    {
        k--;
        cin>>n;
        A.npush(n);
        cout<<" top "<<A.ntop()<<" min "<<A.nmin();

    }
return 0;
}

