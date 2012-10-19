#include<stdio.h>
#include<string.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
#define forall(i,a,b) for(i=a;i<b;i++)
void solver()
{
  int t,m,i,j,k,cnt;
  scanf("%d%d",&t,&m);
  char s[t][20];
  int hash[t+1];
  forall(i,0,t+1)
      hash[i]=0;
  i=0;
  while(i<t)
    {
      ss(s[i]);
      i++;
    }
forall(i,0,t)
{ 
      cnt=1;
if(s[i][0]!=' ')
 {
  forall(j,i+1,t)
    {
	  //	if(s[i][0]==s[j][0] && s[i][m-1]==s[j][m-1])
	  if(strcmp(s[i],s[j])==0)
	    {  
	      cnt++;
	      s[j][0]=' ';
	    }
    }
	hash[cnt]+=1;
   }
   
}
  forall(i,1,t+1)
    printf("%d\n",hash[i]);

}
int main()
{
  solver();
return 0;
}
