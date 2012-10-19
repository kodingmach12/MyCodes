#include<stdio.h>
// Merge sort technique - O(nlogn) algorithm is used
void swap(int *a,int *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}
long long merge(int arr[],int temp[],int low,int mid,int high)
{
    int i=low,j= mid+1,k=low;
    long long invCount = 0;

    while( i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            invCount += (mid-i+1);
        }
    }

    while( i <= mid )
        temp[k++]=arr[i++];

    while( j <= high )
        temp[k++]=arr[j++];

    for(i=low;i<=high;i++)
        arr[i]=temp[i];
  //printf("\n invcount = %d\n",invCount);
  return invCount;
}

long long sortNcount(int arr[],int temp[],int low,int high)
{
    int mid;
    long long invCount=0;
    if(low==high)   return invCount;
    if(high>low)
    {
   /*     if(high==low+1){
            if(arr[low]>arr[high]){
                swap(&arr[low],&arr[high]);
                return 1;
            }
            else
                return 0;
        } */
        mid   = low + (high-low)/2;
        invCount  = sortNcount(arr,temp,low,mid);
        invCount += sortNcount(arr,temp,mid+1,high);
        invCount += merge(arr,temp,low,mid,high);
    }
  return invCount;
}

int main()
{
    int n=6,i;
    scanf("%d",&n);
    int arr[n],temp[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    long long invcount = sortNcount(arr,temp,0,n-1);
    printf("%lld\n",invcount);
return 0;
}
