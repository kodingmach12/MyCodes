#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
#define X first
#define Y second

#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}

#define N 1001
PII b[N];
int a[N];
int s[N][N];

int sum(int i1,int i2,int j1,int j2)
{
	if(i1>i2 || j1>j2) return 0;
	i1--;j1--;
	return s[i2][j2]-s[i2][j1]-s[i1][j2]+s[i1][j1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("FINDSEQ_0.in","r",stdin);
	freopen("FINDSEQ_0_my.out","w",stdout);
	freopen("log.txt","w",stderr);
#endif
	int T,tst=0;
	for(scanf("%d",&T);T--;)
	{
		int n,i,j,k;
		char w[6];
		scanf("%d %s",&n,w);
		int p[5];
		for(i=0;i<5;i++)
			p[i]=w[i]-'1';
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i].X);
			if(p[1]>p[3]) b[i].X*=-1;
			b[i].Y=i;
		}
		if(p[1]>p[3]) for(i=0;i<5;i++) p[i]=4-p[i];
		sort(b+1,b+1+n);
		int m=0;
		for(i=1;i<=n;i=j)
		{
			m++;
			for(j=i;j<=n && b[i].X==b[j].X;j++)
				a[b[j].Y]=m;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				s[i][j]=(a[i]==j)+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		PII x[3]={PII(p[0],0),PII(p[2],2),PII(p[4],4)};
		sort(x,x+3);
		int mini=x[0].Y;
		int midi=x[1].Y;
		int maxi=x[2].Y;
		bool found=false;
		int tot=0;
		int logn=0;
		int logn2=0;
		for(i=2;i<n && !found;i++)
		{
			for(j=i+2;j<n && !found;j++)
				if(a[i]<a[j])
				{
					tot++;
					int l[5],r[5],L[5],R[5];
					for(k=0;k<5;k+=2)
					{
						if(k==0) l[k]=1,r[k]=i-1; else
						if(k==2) l[k]=i+1,r[k]=j-1; else
							l[k]=j+1,r[k]=n;
						if(p[k]<p[1]) L[k]=1,R[k]=a[i]-1; else
						if(p[k]<p[3]) L[k]=a[i]+1,R[k]=a[j]-1; else
							L[k]=a[j]+1,R[k]=m;
						if(sum(l[k],r[k],L[k],R[k])==0) break;
					}
					if(k<5) continue;

					logn++;
					int lo=L[mini]-1,hi=R[mini];
					while(lo+1<hi)
					{
						int md=(lo+hi)/2;
						if(sum(l[mini],r[mini],L[mini],md)>0) hi=md; else lo=md;
					}
					int val_min=hi;
					MAX(L[midi],hi+1);
					if(sum(l[midi],r[midi],L[midi],R[midi])==0) continue;

					logn2++;
					lo=L[maxi],hi=R[maxi]+1;
					while(lo+1<hi)
					{
						int md=(lo+hi)/2;
						if(sum(l[maxi],r[maxi],md,R[maxi])) lo=md; else hi=md;
					}
					int val_max=lo;
					MIN(R[midi],lo-1);
					if(sum(l[midi],r[midi],L[midi],R[midi])==0) continue;

					found=true;
					int ans[5]={-1,i,-1,j,-1};

					for(k=l[mini];a[k]!=val_min;k++);
					ans[mini]=k;

					for(k=l[maxi];a[k]!=val_max;k++);
					ans[maxi]=k;

					for(k=l[midi];!(L[midi]<=a[k] && a[k]<=R[midi]);k++);
					ans[midi]=k;

					for(k=0;k<5;k++)
						printf("%d%c",ans[k]-1,k<4?' ':'\n');
				}
		}
		if(!found) puts("-1");
		fprintf(stderr,"tst=%d\tn=%d\t%s\ttot=%d\tlogn=%d\tlogn2=%d\n",++tst,n,found?"exist":"no",tot,logn,logn2);
	}
	return 0;
}
