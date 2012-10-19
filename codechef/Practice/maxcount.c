#include<stdio.h>
void solver()
{
int len=0;
scanf("%d",&len);
int arr[10001]={0};
 int i=0,max_freq=-1,max_value=0,n=0,maxval=0;
 while(len--)
 { 
     scanf("%d",&n);
     arr[n]+=1;
     if(maxval < n)
       maxval=n;
 }   
 max_value=maxval;
 max_freq=arr[maxval];
 for(i=maxval-1;i>=1;i--)
 {
   if(arr[i] >= max_freq)
   {
	max_value=i;
	max_freq=arr[i];
   }

 }
 printf("%d %d\n",max_value,max_freq);
}


int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
	solver();
return 0;
}
