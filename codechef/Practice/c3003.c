#include<stdio.h>
#include<string.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
void solver()
{
  char s[1000],t[1000],c;
  int slen,tlen,i,j,k,cnt=0;
  char *p1,*p2;
  ss(s);
  ss(t);
  slen=strlen(s);
  tlen=strlen(t);
  int hash[26]={0};
  for(i=0;i<slen;i++)
    hash[s[i]-97]++;
  for(i=0;i<tlen;i++)
    hash[t[i]-97]=0;
  for(i=0;i<26;i++)
    if(hash[i]!=0)
      printf("%c%d",i+97,hash[i]);
  printf("\n");
}
int main()
{
 solver();
return 0;
}
