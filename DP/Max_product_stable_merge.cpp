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
int getmin(int a[],int n);
/*Main code begins now */
void solve()
{
    vector<int> a,b,c;
    int i,j,k,n,t1,t2,t3,res;
    cin>>n;
    FOR(i,0,n){
        cout<<"in";
        t1=rand()%100;
        t2=rand()%99;
        a.push_back(t1);
        b.push_back(t2);
    }
    i=0;
    j=0;
    while( i<n && j<n )
    {
        cout<<"in";
        t1=a[i]*b[j];
        t2=((i+1)<n) ? (a[i]*a[i+1]) : -1 ;     // int_min
        t3=((j+1)<n) ? (b[j]*b[j+1]) : -1 ;     //int_min
        res= max(t1,max(t2,t3));
        if(res==t1)
        {
            c.push_back(a[i]);
            c.push_back(b[j]);
            i++;
            j++;
        }
        else if(res==t2)
        {
            c.push_back(a[i]);
            c.push_back(a[i+1]);
            i+=2;
        }
        else
        {
            c.push_back(b[j]);
            c.push_back(b[j+1]);
            j+=2;
        }
    }
    while(i<n)
        c.push_back(a[i++]);
    while(j<n)
        c.push_back(b[j++]);

    cout<<"A: "<<endl;
    FOR(i,0,n)
        cout<<" "<<a[i];
    cout<<endl;

    cout<<" B:"<<endl;
    FOR(i,0,n)
        cout<<" "<<b[i];
    cout<<endl;

    cout<<" C: "<<endl;
    FOR(i,0,2*n)
        cout<<" "<<c[i];
    cout<<endl;
}


/*Main code ends now */
int main()
{
	int T=1,testnum;
	//cin>>T;
	for(testnum=1;testnum<=T;testnum++)
	{
		solve();
	}
}
