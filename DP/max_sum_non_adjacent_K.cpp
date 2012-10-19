#include<stdio.h>
#include<limits.h>
#include<malloc.h>
long maxsum(int n,int k,long *sums)
{
    long *maxsums = (long*)malloc(sizeof(long)*n);
    int i;
    long add = 0;
    for(i=n-1;i>=n-k;i--)
    {
        add += sums[i];
        maxsums[i] = add;
    }
    for(i = n-k-1;i>=0;i--)
    {
        int j;
        long sum =0,max = 0,cur;
        for(j=0;j<=k;j++)
        {
            cur = sum;
            if((i+j+1)<n)
                cur += maxsums[i+j+1];
            if(cur > max)
                max = cur;
            sum += sums[i+j];
        }
      maxsums[i] = max;
    }
    return maxsums[0];
}

int main(){
    int cases=0,casedone=0;
    int  n,k;
    long *array = (long*)malloc(sizeof(long)*n);
    fscanf(stdin,"%d %d",&n,&k);
    int i =0;
      while(casedone < n){
            fscanf(stdin,"%ld",&array[casedone]);
        casedone++;
      }
    printf("%ld",maxsum(n,k,array));
}
