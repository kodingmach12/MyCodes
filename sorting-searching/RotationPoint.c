#include<stdio.h>

int _Rpoint(int arr[],int low,int high)
{
    if(arr[low] <= arr[high])
        return 0;
    if(low >= high)
        return 0;
    int mid = (low+(high-low)/2);
    if(arr[mid-1] > arr[mid])
        return mid;
    if(arr[mid] > arr[mid+1])
        return mid+1;
    if(arr[low] < arr[mid])
        return _Rpoint(arr,mid+1,high);
    if(arr[mid] < arr[high])
        return _Rpoint(arr,low,mid-1);
}

int Rpoint(int arr[],int size)
{
        int low=0,high=size-1;
    return _Rpoint(arr,low,high);
}

int main()
{
    int arr[]={7,8,9,10,11,12,13,14,1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nThe point of rotation is %d",Rpoint(arr,size));
return 0;
}
