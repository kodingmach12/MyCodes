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
    cin>>K>>N;
    char s[50][51],p[51],*ptr;
    for(int i=0;i<K;i++)
        scanf("%s",&s[i]);
    for(int i=0;i<N;i++){
        scanf("%s",&p);
      //  printf("input = %s\n",p);
        bool res=false;
        if(strlen(p)>=47)
        {
            printf("Good\n");
            res=true;
        }
        for(int i=0;i<K && !res;i++){
            ptr=s[i];
            if(strstr(p,ptr)!=NULL){
                printf("Good\n");
                res=true;
            }
        }
        if(!res)
            printf("Bad\n");
    }
  /*vector<string> s;
    string p;
    for(int i=0;i<K;i++){
            cin>>p;
            s.push_back(p);
    }
    for(int i=0;i<N;i++)
    {
        cin>>p;
        bool res=false;
        if(p.size() >= 47)
        {
            res=true;
            cout<<p<<" Good1"<<endl;
        }
        if(!res)
        {
             for(int i=0;i<K && !res;i++)
             {
                string q=s[i];
                if(p.find(q) > 0 )
                {   res=true;
                    cout<<p<<" Good2"<<endl;
                }
             }
        }
        if(!res)
            cout<<p<<" Bad"<<endl;
    }*/
}
int main()
{
    int tcases,i;
    //cin>>tcases;
    //for(i=1;i<=tcases;i++)
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
