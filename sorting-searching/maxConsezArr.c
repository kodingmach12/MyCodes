#include<stdio.h>
int maxConseqArray(int arr[],int size,int *num)
{
    if(!size)
        return;
    int in=0,prev=arr[0],global=1,local=1,current=0;
    int i=0,j=0;
//1 1 1  2 2 2 2 2 2 4 3 3 3 1 1 1 1 1 1 1
    for(i=1;i<size;i++)
    {   current=arr[i];
        if(current==prev)
            local++;
        else
        {
                prev=current;
                if(local>global)
                {   *num=arr[i-1];
                    global=local;
                }
                    local=1;

        }
    }
    if(local>global && i==size)
    {   *num=arr[i-1];
        global=local;
    }

return global;
}
int main()
{
    int  arr[]={1,1,1,2,2,2,2,2,4,3,3,3,1,1,1};
    int num=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nthere are %d occurences of %d",maxConseqArray(arr,size,&num),num);

}
