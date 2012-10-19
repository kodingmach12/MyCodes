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


/*Main code begins now */
void solve()
{
    int n,m;
    cin>>n>>m;
    char mat[n][m];
    int i,j;
    FOR(i,0,n)
        FOR(j,0,m)
            cin>>mat[i][j];
    bool res1=false,res2=false;
    int res=0;
    for(j=0;j<m;j++)
    {
        if(mat[0][j]=='#')
            res1=true;
        if(mat[n-1][j]=='#')
            res2=true;
    }
    if(!res1 || !res2){
        cout<<-1<<endl;
        return;
    }

    for(i=n-1;i>=0;)
    {
        for(j=m-1; j>=0; j--)
        {
            if(mat[i][j]=='#')
        }
    }

}
int main()
{
    int t,i;
   // cin>>t;
    //FOR(i,0,t)
	solve();
}
