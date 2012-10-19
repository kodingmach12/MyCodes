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
    long long int n,i,j,r,aspots=0,bspots=0;
    cin>>r;
    string a,b;
    cin>>a>>b;
    int alen=a.size(),blen=b.size();
    char a1,b1;
    int gcdab=gcd(alen,blen);
    int lcmab= (alen*blen)/gcdab;
    LL turns=r;
    if(r > lcmab)
        turns = lcmab;

    FOR(i,0,turns)
    {
        a1=a.at(i%alen);
        b1=b.at(i%blen);
        if( a1==b1 )
            continue;
        else if( (a1=='R' &&  b1=='S') ||(a1=='S' &&  b1=='P' ) || (a1=='P' &&  b1=='R' )  )
             bspots++;
        else if( (b1=='R' &&  a1=='S') ||(b1=='S' &&  a1=='P' ) || (b1=='P' &&  a1=='R' )  )
             aspots++;
    }
    LL turnsleft=(r%turns);
    aspots *= (r/turns);
    bspots *= (r/turns);
    FOR(i,0,turnsleft)
    {
        a1=a.at(i%alen);
        b1=b.at(i%blen);
        if( a1==b1 )
            continue;
        else if( (a1=='R' &&  b1=='S') ||(a1=='S' &&  b1=='P' ) || (a1=='P' &&  b1=='R' )  )
             bspots++;
        else if( (b1=='R' &&  a1=='S') ||(b1=='S' &&  a1=='P' ) || (b1=='P' &&  a1=='R' )  )
             aspots++;
    }
    cout<<aspots<<" "<<bspots<<endl;
}

/*Main code ends now */
int main()
{
	solve();
}
