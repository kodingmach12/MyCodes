#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void three_sum(int s[],int *a,int *b,int *c,int n)
{
    int i=0,j=0,start=0,end=n-1,sum;

  while(end>=2)
  {
        i=0;
        j=end;
    while(i<=j)
    {
        sum=s[i]+s[j];
        if(sum==s[end])
        {
            printf("%d  %d  %d\n",s[i],s[j],s[end]);
                *a=s[i];
                *b=s[j];
                *c=s[end];
                i++;
                j--;
        }
        if(sum<s[end])
                i++;
        if(sum>s[end])
                j--;
    }
    end--;

  }
}
int main()
{
    int s[7]={5,8,13,14,19,21,27},n,i,p,q,r;
    i=0;
    n=7;
    //while(i<n){
      //  scanf("%d",a+i);
        //i++; }
    while(i<n)
        printf(" %d ",s[i++]);
    printf("\n");
    //scanf("%d",&n);
    three_sum(s,&p,&q,&r,n);
    printf("  %d + %d = %d\n",p,q,r);

return 0;
}

