//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin())
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
bool isprime(int );

/*Main code begins now */
void solve()
{
    int N;
    cin>>N;

    int initial[N][N],final[N][N],fin[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>initial[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            cin>>final[i][j];
            fin[i][j]=final[i][j];
        }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
             final[i][j]^= initial[i][j];

    int rows[N],cols[N];
    if(final[0][0]==0)
    {
        for(int i=0;i<N;i++)
            if(final[0][i]==0)
                cols[i]=1;
            else
                cols[i]=0;
        for(int i=0;i<N;i++)
            if(final[i][0]==0)
                rows[i]=1;
            else
                rows[i]=0;

    }
    else if(final[0][0]==1)
    {
        for(int i=0;i<N;i++)
            if(final[0][i]==1)
                cols[i]=1;
            else
                cols[i]=0;
        for(int i=0;i<N;i++)
            if(final[i][0]==0)
                rows[i]=1;
            else
                rows[i]=0;
    }
    /*
    cout<<"Rows : ";
    for(int i=0;i<N;i++)
        cout<<rows[i]<<" ";
    cout<<endl;
    cout<<"Cols : ";
    for(int i=0;i<N;i++)
        cout<<cols[i]<<" ";
    cout<<endl;
    */
    int rowcount=0,colcount=0;
    for(int i=0;i<N;i++){
        if(rows[i])
            rowcount++;
        if(cols[i])
            colcount++;
    }
    if( (rowcount+colcount)>N )
    {
        for(int i=0;i<N;i++)
        {
            rows[i] = !rows[i];
            cols[i] = !cols[i];
        }
        rowcount = N-rowcount;
        colcount = N-colcount;
    }

    if( rowcount==colcount && rowcount==0)
    {
        cout<<"0"<<endl;
        return;
    }

    for(int i=0;i<N;i++)
        if( rows[i] )
            for(int j=0;j<N;j++)
                initial[i][j] = !initial[i][j];

    for(int i=0;i<N;i++)
    {
        if( cols[i]==1 )
            for(int j=0;j<N;j++)
            {
                initial[j][i] = !initial[j][i];
            }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(initial[i][j]!= fin[i][j])
            {
                cout<<"-1";
                return;
            }
        }
    }

    cout<<rowcount<<endl;
    for(int i=0;i<N;i++)
        if(rows[i]==1)
            cout<<i<<endl;
    cout<<colcount<<endl;
    for(int i=0;i<N;i++)
        if(cols[i]==1)
            cout<<i<<endl;

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

bool isprime(int n)
{
    if(n<=1)  return false;
    if(n==2)    return true;
    if(n%2==0)  return false;
    int i;
    for(i=3; i*i <=n; i+=2)
        if(n%i==0)  return false;
return true;
}
