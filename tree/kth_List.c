#include<stdio.h>
void print(int arr[],int size)
{
    int i=0;
    printf("\n");
    while(i<size)
    {
        printf("    %d",arr[i++]);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int lo,int hi)
{
    int pivot=arr[lo];
    int lb=lo,ub=hi,tmp;
    while(lb<ub)
    {
        while(arr[lb]<=pivot && lb < hi)
            lb++;
        while(arr[ub]>pivot)
            ub--;
        if(lb<ub)
            swap(&arr[lb],&arr[ub]);
    }
    arr[lo]=arr[ub];
    arr[ub]=pivot;
return ub;
}
int partition2(int arr[],int size)
{
    if(size<=1)
        return;
    int pivot=arr[0];
    swap(&arr[0],&arr[size-1]);
    //print(arr,size);
    int insert_pos=0,i=0,temp;
    for(i=0;i<size;i++)
    {
           if(arr[i] < pivot)
         {
             temp=arr[insert_pos];
             arr[insert_pos]=arr[i];
             arr[i]=temp;
             insert_pos++;
         }
         }
   swap(&arr[size-1],&arr[insert_pos]);
   return insert_pos;
}

int kthList(int arr[],int k,int lower,int upper)
{
    //printf(" \n     k:   %d lower: %d upper:   %d ",k,lower,upper);

    if(k < 0  || k > (upper+1) )
        return -1;
    int pos=partition(arr,lower,upper);
    printf(" \npos:  %d     k:   %d lower: %d upper:   %d ",pos,k,lower,upper);
    print(arr,upper);
    if(pos+1==k)
        return arr[pos];
    if(pos+1<k)
        return kthList(arr,k,pos+1,upper);
    else
    {
     return kthList(arr,k,lower,pos-1);
    }
}

int main()
{
int arr[]={4,5,1,2,7,6,8,9,12,23,45,11,3};
int size=sizeof(arr)/sizeof(arr[0]);
int k=1;
print(arr,size);
//scanf("%d",&k);
printf("\n%d\n",partition2(arr,size));
print(arr,size);
//for(k=0;k<15;k++)
{
//   printf("\nthe %dth element is %d",k,kthList(arr,k,0,size-1));
}
  return 0;
}
