#include<stdio.h>
void print(int arr[],int size)
{
    int i=0;
    for(i=0;i<size;i++)
        printf("   %d  ",arr[i]);
    printf("\n");
}
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void maxheap(int arr[],int size)
{
int i=0,j=0;
int tmp=0,s=size;
size--;
    for(i=size/2;i>=0;i--)
    {
        j=2*i;
        if(arr[i] > arr[j])
                swap(&arr[i],&arr[j]);

        if(arr[j] > arr[j+1])
               swap(&arr[j],&arr[j+1]);
         }
}
void minheap(int arr[],int size)
{
int i=0,j=0;
int tmp=0,s=size;
size--;
    for(i=size/2;i>=0;i--)
    {
        j=2*i;
        if(arr[j] > arr[j+1])
               swap(&arr[j],&arr[j+1]);
        if(arr[i] > arr[j])
                swap(&arr[i],&arr[j]);
    }
}
int main()
{
int arr[]={1,2,3,5,4,6,9,8,7,10};
int size=sizeof(arr)/sizeof(arr[0]);

print(arr,size);
//minheap(arr,size);
int i=0;
for(i=0;i<size;i++)
{
    maxheap(arr,size-1);
    print(arr,size);
}
return 0;
}
