#include<stdio.h>
int main()
{
int n,m;
scanf("%d%d",&n,&m);
char arr[n][m+1];
int i;
for(i=0;i<n;i++)
scanf("%s",arr[i]);
int max=0,pos=-1,j,cnt=0;
char hash[n];
for(i=0;i<n;i++)
hash[i]=0;


for(j=0;j<m;j++)
{
max=~0;
 pos=-1;
for(i=0;i<n;i++)
{
if(arr[i][j]-'0'>max)
max=arr[i][j]-'0';
}
for(i=0;i<n;i++)
{
if((arr[i][j]-'0')==max && hash[i]==0)
{
cnt++;
hash[i]=1;
}
}
}
printf("%d\n",cnt);
return 0;
}
