#include<stdio.h>
#include<string.h>
void solver()
{
 int len=0,i=0,j=0,k=0,c;
 int lcase[27]={0},ucase[27]={0};
 char str[501];
 scanf("%s",str);
 len=strlen(str);
 for(i=0;i<len;i++)
 {  c=str[i];
    if(c>=65 && c<=91)
        ucase[c-64]+=1;
    else if(c>=97 && c<=123)
        lcase[c-96]+=1;
 }
 /*
 for(i=1;i<=26;i++)
 {
   if(lcase[i]!=0)
    printf("\n%c    %d",i+96,lcase[i]);

 }
 printf("\n");
 for(i=1;i<=26;i++)
 {
  if(ucase[i]!=0)
    printf("\n%c    %d",i+64,ucase[i]);
  }
 printf("\n");
*/
    int nr[501]={0},dr[11]={0},rep=0;
    long int ans=1;
    for(i=1;i<=len;i++)
        nr[i]=i;
    for(i=1;i<=26;i++)
    {
        rep=lcase[i];
        if(rep==0 || rep==1)
            ;
        else
        {
            for(j=1;j<=rep;j++)
                dr[j]=j;
            for(j=2;j<=rep;j++)
            {
                for(k=dr[j];k<=len;k+=dr[j])
                {
                    if(nr[k]>=k)
                    {
                      nr[k]/=k;
                      break;
                    }
                }
            }
        }
    }

    for(i=1;i<=26;i++)
    {
        rep=ucase[i];
        if(rep==0 || rep==1)
            ;
        else
        {
            for(j=2;j<=rep;j++)
                dr[j]=j;
            for(j=2;j<=rep;j++)
            {
                for(k=dr[j];k<=len;k+=dr[j])
                {
                    if(nr[k]>=k)
                    {
                      nr[k]/=k;
                      break;
                    }
                }
            }
        }
    }

for(i=1;i<=len;i++)
{
   ans*=nr[i];
  ans%=1000000007;

}  printf("%ld\n",ans);
/*for(i=1;i<=len;i++)
   printf("\nNr :-%d %d",i,nr[i]);
for(i=1;i<=len;i++)
    printf("\nDr :-%d %d",i,dr[i]);
*/
}
int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
	solver();
return 0;
}
