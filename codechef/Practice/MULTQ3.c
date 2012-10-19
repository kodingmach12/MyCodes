//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
 
 
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
 
using namespace std;
//FastIO begin
#define BUFFERSIZE 2000000
char *ipos, *opos, InpFile[BUFFERSIZE], OutFile[BUFFERSIZE], DIP[20];
inline int ni(int flag=0) {
 
while(*ipos <= 32) ++ipos;
if ( flag ) return (*ipos++ - '0'); /* For getting Boolean Characters */
int x=0, neg = 0;char c;
while( true ) {
c=*ipos++; if(c == '-') neg = 1;
else {
if (c<=32) return neg?-x:x;
x=(x<<1)+(x<<3)+c-'0';
}
}
}
inline void pi(int x,int flag = 1) {
int y,dig=0;
while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
while (dig--) *opos++=DIP[dig];
*opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
ipos = InpFile; opos = OutFile;
fread(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO() {
fwrite(OutFile,opos-OutFile,1,stdout);
}
//FastIO end
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define fill(a,v) memset(a, v, sizeof a)
#define sz size()
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define all(x) x.begin(), x.end()
#define gcd __gcd
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
 
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;
 
/*Main code begins now */
int testnum;
 
unsigned long long int* d;
int* prop;
int* lo;
int* hi;
 
 
void init(int i,int a,int b)
{
lo[i]=a;
hi[i]=b;
d[i]=(b-a+1ll)<<40;
if(a!=b)
{
init(2*i+1,a,(a+b)/2);
init(2*i+2,(a+b)/2+1,b);
}
}
 
void update(int a,int b,int i)
{
if(a==lo[i]&&b==hi[i])
{
d[i]=((d[i]<<44)>>4)+(d[i]>>20);
if(prop[i]==0)
prop[i]=1;
else if(prop[i]==1)
prop[i]=2;
else
prop[i]=0;
}
else
{
if(a<=hi[2*i+1]&&b<=hi[2*i+1])
{
update(a,b,2*i+1);
d[i]=d[2*i+1]+d[2*i+2];
if(prop[i]==1)
d[i]=((d[i]<<44)>>4)+(d[i]>>20);
else if(prop[i]==2)
d[i]=((d[i]<<24)>>4)+(d[i]>>40);
}
else if(a>=lo[2*i+2]&&b>=lo[2*i+2])
{
update(a,b,2*i+2);
d[i]=d[2*i+1]+d[2*i+2];
if(prop[i]==1)
d[i]=((d[i]<<44)>>4)+(d[i]>>20);
else if(prop[i]==2)
d[i]=((d[i]<<24)>>4)+(d[i]>>40);
}
else
{
update(a,hi[2*i+1],2*i+1);
update(lo[2*i+2],b,2*i+2);
d[i]=d[2*i+1]+d[2*i+2];
if(prop[i]==1)
d[i]=((d[i]<<44)>>4)+(d[i]>>20);
else if(prop[i]==2)
d[i]=((d[i]<<24)>>4)+(d[i]>>40);
}
}
}
 
 
int query(int a,int b,int i,int sum)
{
if(a==lo[i]&&b==hi[i])
{
if(sum==0) return (d[i]<<4)>>44;
if(sum==1) return (d[i]<<44)>>44;
if(sum==2) return (d[i]<<24)>>44;
}
else
{
sum=sum+prop[i];
if(sum>=3)
sum-=3;
if(a<=hi[2*i+1]&&b<=hi[2*i+1])
{
return query(a,b,2*i+1,sum);
}
else if(a>=lo[2*i+2]&&b>=lo[2*i+2])
{
return query(a,b,2*i+2,sum);
}
else
{
return query(a,hi[2*i+1],2*i+1,sum)+query(lo[2*i+2],b,2*i+2,sum);
}
}
return 0;
}
 
 
int main()
{
InitFASTIO();
int i,N,max,lines,mode,a,b;
N=ni(); lines=ni();
max=1;
while(max<N)
max*=2;
d=new unsigned long long int[2*max-1];
prop=new int[2*max-1];
lo=new int[2*max-1];
hi=new int[2*max-1];
init(0,0,max-1);
for(i=0;i<lines;i++)
{
mode=ni(); a=ni(); b=ni();
 
if(mode==0)
update(a,b,0);
else
pi(query(a,b,0,0));
}
FlushFASTIO();
}