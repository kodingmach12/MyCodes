#include<iostream>
#include<stack>
using namespace std;
class stackwithMin
{
    stack<int> s;
    stack<int> min;
    public:
    void npush(int a)
    {
        s.push(a);
        if(min.empty()  || a<=min.top() )
            min.push(a);
    }
    int ntop()
    {
        if(s.empty())
            return -1;
        return s.top();
    }
    int nmin()
    {
        if(min.empty())
            return 100000;
        return min.top();
    }
    void npop()
    {
        if(s.empty())
        {
            cout<<" No elements "<<endl;
        }
        else
        {
                int a=s.top();
                s.pop();
                if(a==min.top())
                    min.pop();
        }
    }
    bool empty()
    {
        if(s.empty())
            return true;
        return false;
    }
};
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
