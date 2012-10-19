#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

typedef long long LL;
typedef unsigned long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
//const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 100001
#define K 5*N
int f4[N],f7[N];
int dif[N];
int cnt[2*K];
LL ans[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	cnt[K+0]=1;
	int n;
	for(n=1;n<N;n++)
	{
		f4[n]=f4[n/10]+(n%10==4);
		f7[n]=f7[n/10]+(n%10==7);
		dif[n]=dif[n-1]+f4[n]-f7[n];
		ans[n]=ans[n-1]+cnt[K+dif[n]]++;
	}
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d\n",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}
