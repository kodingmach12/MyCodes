#include<iostream>
#include<stack>
using namespace std;
class stackwithMaxFreqItem
{



};
int main()
{
    stackwithMaxFreqItem A;
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

