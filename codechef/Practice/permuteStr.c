#include<stdio.h>
#include<string.h>
void swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}
int min[120]={0},cnt=0;
void permute2(int  a[], int i, int n)
{
  int j,k;
  float temp ;
   if (i == n)
   {
     temp=a[0]+a[1]-a[2]*(float)a[3]/a[4];
    if(temp/1==temp)
       min[cnt]=(int)temp;
     cnt++;
     return;
   }
   else
   {
        for (j = i; j <= n; j++)
       {
        swap((a+i),(a+j));
          permute2(a, i+1, n);
        swap((a+i),(a+j)); //backtrack
       }
   }
}
int main()
{
  int num[5],i,j;
  for(i=0;i<5;i++)
       scanf("%d",&num[i]);
    permute2(num,0,4);
    int v;
    for(i=1;i<120;i++)
      {     if(min[i]>0)
	  v=min[i];
	break;
      }
    for(i=1;i<120;i++)
      {
	//      printf("  %d\n",min[i]);
      if(min[i]<v && min[i]>0  )
	v=min[i];
      }
    printf("%d\n",v);
    return 0;
}
