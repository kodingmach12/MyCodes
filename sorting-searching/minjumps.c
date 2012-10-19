#include<stdio.h>
#include<limits.h>
int calls=0;
int minjumps(int  arr[],int start,int final)
{
    calls++;
    if(start==final)                //base case
        return 0;
    if(arr[start]==0)               // point of no movement -- value is 0
        return INT_MAX;
    int totalsteps=arr[start],i=0,min=INT_MAX,minjmp=0;

    for(i=start+1;i<=final && i<=start+totalsteps;i++)
    {
        //printf("\nstart:%d  totalsteps:%d   final:%d",start,totalsteps,final);
        minjmp=minjumps(arr,i,final);
        //printf("\nmin:%d    minjmp:%d",min,minjmp);
        if(minjmp!=INT_MAX && minjmp+1 < min)
            min=minjmp+1;
    }
return min;
}
int minjumps2(int arr[],int start,int final)
{
    int i=0,j=0,min=0,temp=0,max=0,k=0;
    for(i=0;i<=final;)
    {
        temp=0;
        max=0;
        if(i+arr[i]>=final)
        {
            min++;
            break;
        }
        for(j=i+1;j<=i+arr[i] && j<=final;j++)
        {
            temp=j+arr[j];
            if(temp>max)
            {
                    max=temp;
                    k=j;
            }
        }
        i=k;
        min++;
    }
return min;
}
int main()
{
    //int arr[19]={};

    int arr[]={10,1,3,0,4,1,2,1,3,6,1,1,1,1,2,3,3,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    for(i=0;i<size;i++)
        printf("  %d",arr[i]);
    printf("\nThe size of path is %d",size);
//    printf("\nMin jumps %d",minjumps(arr,0,size-1));
    printf("\nMin jumps (2) %d",minjumps2(arr,0,size-1));
    printf("\nThe total calls are %d\n",calls);
return 0;
}
