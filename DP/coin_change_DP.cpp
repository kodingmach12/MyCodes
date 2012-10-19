#include<iostream>
#include<algorithm>
#include<cassert>
#define MAX 1000000
#define forall(i,a,b) for(i=a;i<=b;i++)
#define iforall(i,a,b) for(i=a;i>=b;i--)
#define INFINITY  10000000
using namespace std;

int coin_Change_DP(int coins[], int n, int sum)
{
    assert(sum>0);
    int v[sum+1],i,j,res=0;
    for(i=0;i<=sum;i++)
        v[i] = INFINITY;
    v[0]=0;
    for(i=1;i<=sum;i++){
        for(j=0;j<n;j++){
            if( i-coins[j]>=0 &&    ( v[ i-coins[j] ] + 1 ) < v[i] )
                v[i]=1+ v[i-coins[j]];
        }
    }
    for(i=0;i<=sum;i++)
        cout<<" "<<v[i];

    res=v[sum];
    free(v);
return res;
}
int main()
{
    int coins[]={5,6,8,9,11,13,14,15,10,9};
    int n=sizeof(coins)/sizeof(coins[0]);
    int sum;
    cin>>sum;
    int val=coin_Change_DP(coins,n,sum);
    cout<<endl<<" min coins needed is "<<val<<endl;
return 0;
}
