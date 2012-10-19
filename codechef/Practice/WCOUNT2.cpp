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

#define MOD 1000000007
#define N 10101
int fac[N]={1,1};
int inv[N]={0,1};
int invfac[N]={1,1};
char s[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	for(n=2;n<N;n++)
	{
		fac[n]=LL(n)*fac[n-1]%MOD;
		inv[n]=LL(inv[MOD%n])*(MOD-MOD/n)%MOD;
		invfac[n]=LL(inv[n])*invfac[n-1]%MOD;
	}
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%s",s);
		int num[128]={0};
		for(n=0;s[n];n++)
			num[s[n]]++;
		int ans=fac[n];
		for(int i=0;i<128;i++)
			ans=LL(ans)*invfac[num[i]]%MOD;
		printf("%d\n",ans);
	}
	return 0;
}
