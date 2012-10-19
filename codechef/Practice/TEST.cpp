#include<iostream>
#include <cstring>
#include <string>
#include <sstream>
#include<vector>
#include<algorithm>
using namespace std;
void display(vector<int> &v)
{
    int i=0;
    for(i=0;i!=v.size();i++)
        cout<<v[i]<<endl;
}
void solver()
{

    vector<int> s;
    int i=0,flag=1,n;
    while((cin>>n))
    {

        if(n==42){
               flag=0;
               break;
        }
        else if(flag)
            s.push_back(n);

    }
    display(s);
}
int main()
{
  solver();
return 0;
}


