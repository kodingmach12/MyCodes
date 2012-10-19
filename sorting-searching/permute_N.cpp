#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void permute(int p[], int start, int len)
{
    if(start == len )
    {
         for(int i=1;i<=len;i++)
              cout<<" "<<p[i];
            cout<<endl;
    return;
    }
    for(int i=start; i<=len; i++)
    {
        swap(p[start],p[i]);
        permute(p,start+1,len);
        swap(p[start],p[i]);
    }
}
int main()
{
    int n;
    cout<<" Enter the range "<<endl;
    cin>>n;
    int p[n+1];
    for(int i=0;i<=n;i++)
        p[i] = i;
    permute(p,1,n);
return 0;
}
