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

int main()
{
    int n;
    cin>>n;
    int totalsteps=0,i=1,powers[20],j=0,start1,start2;
    while(i<n)
    {
        totalsteps ++;
        powers[j++]=i;
        i *= 2;
    }
    int inscount=0;
    cout<<totalsteps<<endl;
    int start,diff,steps,k;
        start=1;
        diff=2;
        steps=1;
    string s;
    for(i=1; i<=totalsteps; i++)
    {
    inscount=0;
    for(j=powers[i-1];j<n;j+=diff)
        for(k=1;k<=steps && (j+k)<=n;k++)
            inscount++;
    cout<<inscount;
    for(j=powers[i-1];j<n;j+=diff)
        for(k=1;k<=steps && (j+k)<=n;k++)
        {
            cout<<" "<<j<<"+"<<j+k<<"="<<j+k;
            inscount++;
        }
        cout<<endl;
    start*=2;
    diff*=2;
    steps*=2;
    }
return 0;
}
