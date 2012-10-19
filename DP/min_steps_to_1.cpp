#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
#define MAX 100000
int minsteps(int n)
{
    assert(n>0);
    if(n==1)    return 0;
    int *dp=(int *)calloc(sizeof(int),n+1);
    int i=0,j=0,a,b,res;
    dp[0]=-1;
    dp[1]=0;
    for(i=2;i<=n;i++)
    {
        a = (i%2)?MAX:dp[i/2];
        b = (i%3)?MAX:dp[i/3];
        dp[i] = 1 + min( dp[i-1] , min(a,b) );
    }

    for(i=0;i<=n;i++)
       cout<<" "<<dp[i];

res=dp[n];
free(dp);
return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<" The minimum steps to 1 are "<<minsteps(n)<<endl;

return 0;
}
