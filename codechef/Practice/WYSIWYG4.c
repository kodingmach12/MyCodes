#include<stdio.h>
#include<string.h>
void reverse(char *s)
{
  char *p=s+strlen(s)-1;
  char t;
  while(s<=p)
    {
      t=*s;
      *s++=*p;
      *p--=t;
    }
}
int main()
{
  int t,alen,blen,i,j,found,foundrev;
  char a[100],b[100];
  scanf("%d",&t);
  while(t--)
    {
      found=0;
      foundrev=0;
      scanf("%s",a);
      scanf("%s",b);
      alen=strlen(a);
      blen=strlen(b);
      //      printf(" %d  %d\n",alen,blen);
      for(j=blen-1,i=alen-1;i>=0 && j>=0;i--)
	{
	  if(b[j]==a[i])
	    j--;
	}
      if(j==-1)
	found=1;

      reverse(b);
      for(j=blen-1,i=alen-1;i>=0 && j>=0;i--)
	{
	  if(b[j]==a[i])
	    j--;
	}
      if(j==-1)
	foundrev=1;
      //      printf("found %d revfound %d",found,foundrev);
      if(found && !foundrev)
	printf("1\n");
      if(!found && foundrev)
	printf("2\n");
      if(found && foundrev)
	printf("3\n");
      if(!found && !foundrev)
	printf("0\n");
    }
 return 0;
}
	    
