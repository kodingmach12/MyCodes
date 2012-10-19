#include<iostream>
using namespace std;
int findFirstInstance(int a[],int size,int k)
{
    if(a[0]==k) return 0;
    int lo=0,mid,hi=size-1;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)>>2;
        if(lo==mid && a[mid]==k || a[mid]==k && a[mid-1]<a[mid] )
            return mid;
        else if(a[mid] >=k)
            hi=mid-1;
        else
            lo=mid+1;
    }
return -1;
}
int findLastInstance(int a[],int size,int k)
{
    if(a[size-1]==k)    return (size-1);
    int lo=0,hi=size-1,mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)>>2;
        if(hi==mid && a[mid]==k || a[mid]==k && a[mid+1]>k)
            return mid;
        else if(a[mid] <= k)
            lo=mid+1;
        else
            hi=mid-1;
    }
return -1;
}

int  findFrequency(int arr[],int size,int k)
{
    if(k > arr[size-1] || k < arr[0])   return 0;
    int a=findFirstInstance(arr,size,k);
    int b=findLastInstance(arr,size,k);
    if(a!=-1 && b !=-1) return b-a+1;
return 0;
}
