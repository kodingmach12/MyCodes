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
bool comparator(int a,int b)
{
    return (a>=b);
}
void display(const vector<int> &v)
{
    for(int i=0;i<v.size();i++)
        cout<<" "<<v[i];
    cout<<endl;
}
/*Main code begins now */
int separateEvenOdd(vector<int>& v)
{
    int start=0,end=v.size()-1;
    while(start<end)
    {   if(v[start]%2==1)
            start++;
        if(v[end]%2==0)
            end--;
        if(v[start]%2==0 && v[end]%2==1)
        {
            swap(v[start],v[end]);
            start++;
            end--;
        }
        //cout<<" start "<<start<<" end "<<end<<endl;
        //display(v);
    }
    //display(v);
return start;
}
void solve(int tc)
{
    int N;
    cin>>N;
    vector<int> v;
    int I,temp;
    FOR(I,0,N)
    {
        cin>>temp;
        v.push_back(temp);
    }
    int mid=separateEvenOdd(v);
    if(mid==N-1)
    {
        sort(v.begin(),v.end(),comparator);
    }
    if(mid == 0)
    {
        sort(v.begin(),v.end());
    }
    else
    {
        sort(v.begin(),v.begin()+mid+1,comparator);
        sort(v.begin()+mid+1,v.end());
    }
    display(v);
}
/*Main code ends now */
int main()
{
	int T=1,testnum;
	cin>>T;
	for(testnum=1;testnum<=T;testnum++)
	{
		solve(testnum);
	}
}

