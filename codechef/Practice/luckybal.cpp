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
    int K,N;
    char s[100001];
    scanf("%s",&s);
    int cnt4=0,cnt7=0;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]=='4')   cnt4++;
        else    cnt7++;
    int res=0;
    int cur4=0,cur7=0;
    for(int i=0;s[i]!='\0';i++){
        if( cur4 == (cnt7-cur7) )
            res++;

        if(s[i]=='4')
            cur4++;
        else
            cur7++;

    }
    printf("%d\n",res);
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
