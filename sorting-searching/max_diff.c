#include<stdio.h>
int maxdifference(int arr[],int size)
{
    if(size<2)  return  0;
    int i=0,min=arr[0],maxdiff=arr[1]-arr[0];
    for(i=1;i<size;i++)
    {
        if(arr[i]-min > maxdiff)
            maxdiff=arr[i]-min;
        if(arr[i]<min)
            min=arr[i];
    }

return maxdiff;
}
int main()
{
int arr[]={-1000,2,-113,-44,150};

int size=5;
printf("the maximum difference is %d\n",maxdifference(arr,size));

return 0;
}
