#include<stdio.h>
#include<string.h>
void solver()
{
  int cnt=0;
  char num[100001];
  scanf("%s",num);
  int i=0;
  for(i=0;num[i]!='\0';i++)
    if(num[i]!='4' && num[i]!='7')
      cnt++;
     printf("%d\n",cnt);
}


int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
      solver();
return 0;
}
