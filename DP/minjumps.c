#include<stdio.h>
#include<malloc.h>
#include<limits.h>
int minjumps(int arr[],int size)
{
    if(size==1)
        return 0;
    if(arr[0]==0 && size!=1)
        return INT_MAX;
    int *jumps=(int*)malloc(size*sizeof(int));

    int i=0,j=0,minjmp=0;

    for(i=0;i<size;i++)
        *(jumps+i)=INT_MAX;

    jumps[0]=0;

    for (i = 1; i < size; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                 jumps[i] = jumps[j] + 1;
                 break;
            }
        }
    }
    minjmp=jumps[size-1];
        free(jumps);
return minjmp;
}
int main()
{
    //1,1,3,0,4,1,2,1,3,6,1,1,1,1,2,3,3,1
    int arr[]={1,1,3,0,4,1,2,1,3,6,1,1,1,1,2,3,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    for(i=0;i<size;i++)
        printf("  %d",arr[i]);
    printf("\nThe size of path is %d",size);
    printf("\nThe minimum jumps required to reach the end is %d",minjumps(arr,size));

return 0;
}

