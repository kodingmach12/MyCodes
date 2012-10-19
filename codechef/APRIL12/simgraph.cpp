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
    int n,i,j,k;
    cin>>n;
    PII node,tnode,temp;
    vector< PII > g1,g2;
    FOR(i,0,n)
        FOR(j,0,n)
        {
            cin>>k;
            if(k && i<j)
            {
                temp = mp(i,j);
                g1.push_back(temp);
            }
        }

    FOR(i,0,n)
        FOR(j,0,n)
        {
            cin>>k;
            if(k && i < j)
            {
                temp=mp(i,j);
                g2.push_back(temp);
            }
        }
    //cout<<" size of g1 is "<<g1.size()<<endl;
    //cout<<" size of g2 is "<<g2.size()<<endl;
    /*int ans[n+1];
    ans[0]=0;
    FOR(i,1,n+1)
        ans[i]=i;
    float sim=0.0,res=0.0;
    for(i=0,j=0; i<g1.size() && j<g2.size(); )
    {
        if(g1[i]==g2[j])
            sim += 1.0;
        i++;
        j++;
    }
    res = ( 2.0 * sim )/(float)n;
    cout<< " similarity is " << res <<endl;*/
    int res[n];
    FOR(i,0,n)
        res[i] = i+1;
    FOR(i,0,n/2)
    {
        j = (rand()%n);
        swap(res[j],res[n-j-1]);
    }
    FOR(i,0,n)
        cout<<res[i]<<" ";
    cout<<endl;

    FOR(i,0,n/2)
    {
        j = (rand()%n);
        swap(res[j],res[n-j-1]);
    }
    FOR(i,0,n)
        cout<<res[i]<<" ";
    cout<<endl;
}

/*Main code ends now */
int main()
{
	int T=1,i;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		solve();
	}
}
