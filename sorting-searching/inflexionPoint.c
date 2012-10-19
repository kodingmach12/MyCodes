#include<stdio.h>
int inflexionpoint(int arr[],int size)
{
    int mid=0,low=0,high=size-1;
	if(size==1)
		return -1;

	while(low<=high)
    {
        if((high-low)==1)
                return ((arr[low]<arr[high])? low : high);

		mid=low+(high-low)>>2;    //shift operator for fast operation

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
            low=mid+1;
        else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
            high=mid-1;
    }
}
int main()
{
    int arr[10];
    int i=0;
    while(i<10)
        scanf("%d",&arr[i++]);
    printf("\nThe point is %d\n",arr[inflexionpoint(arr,10)]);
return 0;
}
