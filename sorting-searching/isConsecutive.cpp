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
bool hasDuplicates(int a[], int n,int min)
{
    if(n<2) return false;
    int i=0,j=0;
    FOR(i,0,n)
    {
        if(a[i]<0)
            j = -a[i]-min;
        else
            j = a[i]-min;
        cout<<" j : "<<j<<" a[j] : "<<a[j]<<endl;
        if(a[j]>0)
            a[j] = -a[j];
        else
            return true;
    }
return false;
}
bool isConsecutive(int a[], int n)
{
    if( n  < 1 )   return false;
    if( n == 1 )   return true;
    int sum=a[0],min=a[0],max=a[0],i,j;
    FOR(i,1,n)
    {
        if( a[i]>max )
            max = a[i];
        else if( a[i]<min )
            min = a[i];
        //sum+=a[i];
    }
    cout<<" min :"<<min<<" max "<<max<<endl;
    if( (max-min+1)==n )
    {
        if(hasDuplicates(a,n,min)){
            cout<<"duplicates";
            return false;
        }
        else
            return true;
    }
    else
        return false;
}

/*Main code ends now */
int main()
{
	int T=0,testnum,a[10],n,i,j;
	cin>>n;
	FOR(i,0,n)
        s(a[i]);
    if(isConsecutive(a,n))
        cout<<" Consecutive "<<endl;
    else
        cout<<" Not Consecutive "<<endl;

return 0;
}
