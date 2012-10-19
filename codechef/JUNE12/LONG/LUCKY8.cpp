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
int squareRoot(unsigned int n);

/*Main code begins now */
int digitcount(int a)
{
    int cnt=0;
    while(a){
        cnt++;
        a /= 10;
    }
    return cnt;
}
void solve()
{
    LL L,R,res;
    cin>>L>>R;
    int leftdigit=digitcount(L);
    int rightdigit=digitcount(R);
    if(rightdigit==1)   res=0;
    else if(rightdigit==2)   res=1;
    else if(rightdigit==3)   res=2;
    else{
        for(int i=1;i<=rightdigit;i++)
            if( (i*(rightdigit-i)) > res )
                res= (i*(rightdigit-i));
    }
    cout<<res<<endl;
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
