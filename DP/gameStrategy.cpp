#include<iostream>
#include<algorithm>
#define MAX 1000000
#define forall(i,a,b) for(i=a;i<=b;i++)
#define iforall(i,a,b) for(i=a;i>=b;i--)
using namespace std;
//To Do :- Track the set of coins leading to max
int maxsum(int coins[],int n)
{
    int v[n][n],i,j,a,b,c,p,q;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            v[i][j] = 0 ;

    for(i=n-1;i>=0;i--)
    {
      for(j=i;j<n;j++)
      {
           if(i==j)
                v[i][j] = coins[i];
           else if( j==(i+1) )
                v[i][j] = max(coins[i],coins[j]);
           /*else if(j==(i+2))
                v[i][j] = max(coins[i]+min(coins[i+1],coins[i+2]),coins[i+2]+min(coins[i],coins[i+1]));*/
           else
                v[i][j] = max(coins[i]+min(v[i+1][j-1],v[i+2][j]),coins[j]+min(v[i][j-2],v[i+1][j-1]));
      }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
          cout<<" "<<v[i][j]<<" ";
        cout<<endl;
    }
return v[0][n-1];
}
int main()
{
    int coins[]={11,5,2,4,19,18};
    int n=sizeof(coins)/sizeof(coins[0]);
    int val=maxsum(coins,n);
    cout<<" max  val gained is "<<val<<endl;
return 0;
}
