#include<stdio.h>
int findmin(int arr[],int low,int high)
{

if(arr[low]<arr[high])
	return arr[low];
int mid=low+(high-low)/2;
if(arr[low]<=arr[mid])
    findmin(arr,mid+1,high);
if(arr[mid]<arr[high])  
	findmin(arr,low,mid-1);
}
int main()
{
int arr[10]={7,8,9,10,1,2,3,4,5,6};
printf("\nThe minimum of rotated array is %d\n",findmin(arr,0,9));
}
