//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<cassert>

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

long long int maxDiff(long long int arr[],long long  int arr_size)
{
    if(arr_size==1) return arr[0];
  long long int max_diff = arr[1] - arr[0];
  long long int min_element = arr[0],i;
  for(i = 1; i < arr_size; i++)
  {
    if( (arr[i] - min_element) > max_diff)
        max_diff = arr[i] - min_element;
    else if(arr[i] < min_element)
         min_element = arr[i];
  }
  return max_diff;
}

void solve()
{
    long long int n,i,j;
    sl(n);
    long long int  score[n],max=-1;
    FOR(i,0,n)
        sl(score[i]);
    if(n>1)
         max = maxDiff(score,n);
    if(max==-1 || max==0)
        printf("UNFIT\n");
    else
        printf("%lld\n",max);
}
/*Main code ends now */
int main()
{
	int T=1,testnum;
	scanf("%d",&T);
	assert(T>=1);
	assert(T<=10);
	for(testnum=1;testnum<=T;testnum++)
		solve();
return 0;
}
