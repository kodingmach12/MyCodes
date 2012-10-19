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
    int R,C,k,min,max;
    cin>>R>>C;
    int M[R+1][C+1];
    for(int i=0,min=100000001;i<R;i++){
        for(int j=0;j<C;j++)
        {
             cin>>M[i][j];
             if(min > M[i][j])
                min=M[i][j];
        }
        M[i][C]=min;
    }
    for(int j=0,max=-1;j<C;j++){
        for(int i=0;i<R;i++)
        {
            if(max < M[i][j])
                max=M[i][j];
        }
        M[R][j]=max;
    }
    // /*
    for(int i=0;i<=R;i++){
        for(int j=0;j<=C;j++)
            cout<<" "<< M[i][j];
        cout<<endl;
    }
    //*/
    bool flag=false;
    for(int i=0;i<R;i++)
    {   int k=M[i][C];
        for(int j=0;j<C;j++)
        {
            if(k==M[R][j])
            {
                flag=true;
                break;
            }
        }
    }
    cout<<" Case#:"<< " ";
    if(flag)    cout<<k<<endl;
    else    cout<<"GUESS"<<endl;
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
