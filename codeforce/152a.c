#include<stdio.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
void solver()
{
  int n=0,m=0,succ[100]={0},i=0,j=0,max=0,total=0;
  s(n);
  s(m);
  char grade[n][m+1];
  for(i=0;i<n;i++)
    ss(grade[i]);
  for(i=0;i<m;i++)
    { max=0;
      for(j=0;j<n;j++)
	{
	  if(grade[j][i]-'0'>max)
	    max=grade[j][i]-'0';
	}
      for(j=0;j<n;j++)
	{
	  if(grade[j][i]-'0'==max)
	    succ[j]=1;
	}
    }
  for(i=0;i<100;i++) 
    if(succ[i]==1)
      total++;
  printf("%d",total);
}


int main()
{
  solver();
return 0;
}
