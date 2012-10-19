#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int islucky(int n)
{
int n1=n,res=0,cnt[10]={0},i;
while(n1)
{
    cnt[n1%10]++;
    n1/=10;
}
if(!cnt[0]&&!cnt[1]&&!cnt[2]&&!cnt[4]&&!cnt[6]&& !cnt[7]&& !cnt[9]&& cnt[3]<=cnt[5]&&cnt[5]<=cnt[8])
    res=1;
return res;
}

void solver()
{
    int n,i=0,j=0,res=0,price=0,len=0;
    scanf("%d",&n);
    char menus[100],c;
    for(i=0;i<n;i++)
    {   price=0;
        j=0;
        scanf("%^\n",menus);
        len=strlen(menus);
        j=len-1;
        printf("%d\n",len);
        while(menus[j]!=' ')
        {
            price+=price*10+menus[j]-'0';
            j--;

        }
        printf("%d\n",price);
    if(islucky(price))
        res++;
    }
printf("%d\n",res);
}
int main()
{
  solver();
return 0;
}

