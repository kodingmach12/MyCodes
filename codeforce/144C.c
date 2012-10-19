#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
#define forall(i,a,b) for(i=a;i<b;i++)
#define p(n) printf("%d",n)
#define pl(n) printf("%d\n",n)
#define ps(n) printf("%s",n)
#define psl(n) printf("%s\n",n)
#define w(a,b) while(a<b)
#define sl(a) strlen(a)
#define good 1
#define bad 0
void solver()
{
  char s[100000],t[100000];
  ss(s);
  ss(t);
  int sln,tln,scnt[27]={0},tcnt[27]={0},prev=0,cur=1,i,j,k,req=0,pc,nc,gudcnt=0;
  sln=sl(s);
  tln=sl(t);
  forall(i,0,tln)
    {if(s[i]=='?')
	scnt[0]++;
      else
	scnt[s[i]-96]++;
    tcnt[t[i]-96]++;
    }
  forall(i,1,tln+1)
    {if(scnt[i]>tcnt[i])
	cur=bad;
      else
	req+=tcnt[i]-scnt[i];
    }
  if(cur!=bad && req==scnt[0]){
      prev=good;
      gudcnt++;
    }
  else
    prev=bad;
  forall(i,0,tln+1)
    printf(" %d %d\n",scnt[i],tcnt[i]);
  printf("prev %d cur %d req %d\n",prev,cur,req);

    forall(j,tln,sln)
    {
      pc=s[j-tln];
      nc=s[j];
      cur=bad;
      if(prev==good)
	{
	  if(pc==nc)
	    cur=good;
	  else
	    {	    
	      if(pc=='?')   {    scnt[0]--;
		req++;}
	      else{             scnt[pc-96]--;
		                req++;}
	      if(nc=='?')
		{  scnt[0]++;
		   req--;}
	      else              scnt[nc-96]++;
	      if(req==scnt[0]) 	cur=good;
	    }
	}
      else
	{
	  if(pc!=nc)
	    {
	      if(pc=='?')       scnt[0]--;
	      else
	      {scnt[pc-96]--;
		req++;}
	      if(nc=='?')
		{  scnt[0]++;
		   req--;}
	      else              scnt[nc-96]++;
	      if(req==scnt[0]) 	cur=good;
	    }
	}

      if(cur==good)
	gudcnt++;
      prev=cur;
       forall(i,0,tln+1)
    printf(" %d %d\n",scnt[i],tcnt[i]);
    printf("prev %d cur %d req %d gudcnt %d\n",prev,cur,req,gudcnt);

      } 
  pl(gudcnt);
}
int main()
{
solver();
return 0;
}
