#include<stdio.h>

int islucky(int n)
{
 int cnt[10]={0},i=n;
while(i)
{
    cnt[i%10]++;
    i/=10;
}
if(!cnt[0]&&!cnt[1]&&!cnt[2]&&!cnt[4]&&!cnt[6]&& !cnt[7]&& !cnt[9]&& cnt[3]<=cnt[5]&&cnt[5]<=cnt[8])
    return 1;
return 0;
}
void solver()
{
   long long int n=8,count=0;
    while(count<=50000)
    {
        if(islucky(n))
        {
            count++;
            printf("%lld, ",n);
        }
        n++;
    }
}
int main()
{
  solver();
return 0;
}

