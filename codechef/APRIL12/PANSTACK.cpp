#include<stdio.h>
#include<time.h>
#define mod 1000000007
long long int comb[1001][1001];
long long int bell[1001];
int ncr()
{
  int i;
  for(i=0;i<1001;i++)
    comb[i][i]=1;
  for(i=0;i<1001;i++)
    comb[i][0]=1;
  for(i=2;i<1001;i++)
    {
      int j=1;
      for(;j<=i;j++)
	{
	  comb[i][j]=((comb[i-1][j])%mod+(comb[i-1][j-1])%mod)%mod;
	  //printf("%d ",comb[i][j]);
	}
	//printf("\n");
    }
  for(i=0;i<1001;i++)
    bell[i]=0;
  bell[0]=1;
  bell[1]=1;
  bell[2]=2;
  bell[3]=5;
  bell[4]=15;
  for(i=5;i<=1001;i++)
    {
      int k;
      for(k=0;k<i;k++)
      {
            bell[i] = bell[i] + ((comb[i-1][k])*(bell[k]));
            bell[i] = bell[i] %mod;
      }
    }
}
void solve()
{
  int n;
  scanf("%d",&n);
  int i;
  //for(i=0;i<n+1;i++)
  printf("%lld\n",bell[n]);
}
int main()
{
  int test;
  //clock_t start=clock();
  scanf("%d",&test);
  ncr();
  //printf("Time to preprocess : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
  while(test--)
    solve();
  //printf("Time Elapsed : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
  return 0;
}
