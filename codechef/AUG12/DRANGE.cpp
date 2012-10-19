//Other Includes
#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define fill(a,v) 					memset(a, v, sizeof a)
typedef long long LL;

void solve()
{
    LL N,M;
    LL x,y,z,w;
    cin>>N>>M;
    LL change[N+1];
    fill(change,0);

    for(int i=1;i<=M;i++){
        cin>>w>>x>>y>>z;
        if(w==1){
            change[y] += z;
            change[x-1] -= z;
        }
        else
        {
            change[y] -= z;
            change[x-1] += z;
        }
    }
    LL min = change[1];
    LL max = change[1];
    for( int i=N-1;i>=0;i--)
    {
        change[i] += change[i+1];
        change[i+1] += (i+1);
        LL curval = change[i+1];
        if( curval > max)
            max=curval;
        else if( curval < min )
            min=curval;
    }
     /*    for( int i=1;i<=N;i++)
        cout<<change[i]<<" ";
        cout<<endl;
    */
    LL range= max-min;
    cout<<range<<endl;
}
int main()
{
    int tcases,i;
    cin>>tcases;
    for(i=1;i<=tcases;i++)
    {
        solve();
    }
return 0;
}
