
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
void solve(int tc)
{
    LL R,K,N,temp;
    queue<int> Q;
    cin>>R>>K>>N;
    LL I,J,sum=0,persons=0;
    FOR(I,0,N)
    {
        cin>>temp;
        Q.push_back(temp);
    }
    FOR(I,0,R)
    {
        J=0;
        persons=0;
        while(j<N && persons<=K)
        {
            persons += Q.front();
            temp=Q.front();
            Q.pop_front();
            Q.push_back(temp);
        }
        sum += persons;
    }
    cout<<sum<<endl;
}
int main()
{
    freopen("in.c","r",stdin);
    freopen("csmall.out","w",stdout);
    int tcase;
    cin>>tcase;
    for(int i=1;i<=tcase;i++)
    {
        solve(i);
    }
return 0;
}
