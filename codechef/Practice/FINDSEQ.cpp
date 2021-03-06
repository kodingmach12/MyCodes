#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>

using namespace std;

typedef pair<int,int> pi;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

#define MP make_pair
#define inf 1000000000


int A[1005],pos[6],vals[6];
char B[10];
pi all[1005],C[6];

short prefMin[1005][1005];
short prefMax[1005][1005];
short  sufMin[1005][1005];
short  sufMax[1005][1005];
short  S[1005][1005];
short  X[1005];

int calc(int i,int j,int x,int y)
{
    if(x>=y) return 0;
    return S[y][j]-S[y][i-1]-S[x+1][j]+S[x+1][i-1];
}

int main()
{
	int i,j,k,tests,n;


	scanf("%d",&tests);
	assert(tests>=1 && tests<=60);


	while(tests--)
	{

		scanf("%d%s",&n,B);
		assert(n>=5 && n<=1000);

		int flag=0;
		int l=strlen(B);
		assert(l>=1 && l<=5);
		for(i=0;i<5;i++)
		{
		    int x=B[i]-'0';
		    assert(B[i]>='1' && B[i]<='5');
		    assert(!( flag&(1<<x)) );
		    flag|=(1<<x);
		}

		for(i=1;i<=n;i++)
		{
		    scanf("%d",&A[i]);
		    all[i]=MP(A[i],i);
		    assert(-1000000000<=A[i] && A[i]<=1000000000);
		}


		sort(all+1,all+1+n);

		int totv=0;
		for(i=1;i<=n;i++)
		{
			if(i==1 || all[i].first!=all[i-1].first) ++totv;
			A[all[i].second]=totv;
		}
		++totv;

		for(i=0;i<=totv;i++)
		{
			prefMin[i][0]=prefMax[i][0]=-1;

			for(j=1;j<=n;j++)
			{
				prefMin[i][j]=prefMin[i][j-1];
				prefMax[i][j]=prefMax[i][j-1];

				if(A[j]>i && (prefMin[i][j]<0 || A[j]<A[prefMin[i][j]])) prefMin[i][j]=j;
				if(A[j]<i && (prefMax[i][j]<0 || A[j]>A[prefMax[i][j]])) prefMax[i][j]=j;

				S[i][j]=S[i][j-1]+ (A[j]<i);
			}

			sufMin[i][n+1]=sufMax[i][n+1]=-1;

			for(j=n;j>=1;j--)
			{
				sufMin[i][j]=sufMin[i][j+1];
				sufMax[i][j]=sufMax[i][j+1];

				if(A[j]>i && (sufMin[i][j]<0 || A[j]<A[sufMin[i][j]])) sufMin[i][j]=j;
				if(A[j]<i && (sufMax[i][j]<0 || A[j]>A[sufMax[i][j]])) sufMax[i][j]=j;
			}
		}

		for(j=0;j<5;j++)
		{
			B[j]-='0';
			pos[B[j]]=j;
		}

		int sol=0;
		int iL,iM,iR;
		int i0,i1,i2,i3,i4;

		iL=MIN(B[0],MIN(B[2],B[4]));
		iR=MAX(B[0],MAX(B[2],B[4]));
		iM=B[0]+B[2]+B[4]-iL-iR;

		X[0]=0;
		X[6]=totv;

		for(i1=2;i1<=n && !sol;i1++)
			for(i3=i1+2;i3+1<=n && !sol;i3++)
			{
				if(A[i3]==A[i1]) continue;
				if(A[i3]>A[i1] && B[3]<B[1]) continue;
				if(A[i3]<A[i1] && B[3]>B[1]) continue;

				X[B[1]]=A[i1];
				X[B[3]]=A[i3];
				X[B[0]]=X[B[2]]=X[B[4]]=-1;

				if(pos[iL]==0)
				{
					i0= prefMin[X[iL-1]][i1-1];
					if(i0==-1) continue;
					X[B[0]]=A[i0];

					i4= pos[iR]==4 ? sufMax[X[iR+1]][i3+1] : sufMin[X[iM-1]][i3+1];
					if(i4==-1 ) continue;
					X[B[4]]=A[i4];

					int cnt= calc(i1+1,i3-1, X[B[2]-1] , X[B[2]+1]);
					if(cnt) sol=1;
				}

				if(pos[iL]==4)
				{
					i4 = sufMin[X[iL-1]][i3+1];
					if(i4==-1) continue;
					X[B[4]]=A[i4];

					i0= pos[iR]==0 ? prefMax[X[iR+1]][i1-1] : prefMin[X[iM-1]][i1-1];
					if(i0==-1) continue;
					X[B[0]]=A[i0];

					int cnt= calc(i1+1,i3-1, X[B[2]-1] , X[B[2]+1]);
					if(cnt) sol=1;
				}

				if(pos[iL]==2 && pos[iR]==4)
				{

					i4 = sufMax[X[iR+1]][i3+1];
					if(i4==-1 ) continue;
					X[B[4]]=A[i4];

					i0= pos[iL]==0 ? prefMin[X[iL-1]][i1-1] : prefMax[X[iM+1]][i1-1];
					if(i0==-1) continue;
					X[B[0]]=A[i0];

					int cnt= calc(i1+1,i3-1, X[B[2]-1] , X[B[2]+1]);
					if(cnt) sol=1;
				}


				if(pos[iL]==2 && pos[iR]==0)
				{
					i0= prefMax[X[iR+1]][i1-1];
					if(i0==-1 ) continue;
					X[B[0]]=A[i0];

					i4= pos[iL]==4 ? sufMin[X[iL-1]][i3+1] : sufMax[X[iM+1]][i3+1];
					if(i4==-1) continue;
					X[B[4]]=A[i4];

					int cnt= calc(i1+1,i3-1, X[B[2]-1] , X[B[2]+1]);
					if(cnt) sol=1;
				}

				if(!sol) continue;

				int iB=B[2];
				for(i=2;i<=5;i++) if(i!=iB && i!=iB+1 && X[i]<=X[i-1]) sol=0;

				if(!sol) continue;

				for(i2=i1+1;i2<i3;i2++)
					if(A[i2]>X[B[2]-1] && A[i2]<X[B[2]+1]) break;

				X[B[2]]=A[i2];
				printf("%d %d %d %d %d\n",i0-1,i1-1,i2-1,i3-1,i4-1);
			}
		if(!sol) puts("-1");
	}

	return 0;
}


