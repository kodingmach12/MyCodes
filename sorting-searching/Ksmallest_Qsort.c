#include<stdio.h>
/*
9
12 23 98 89 34 45 32 56 41
*/
int partition(int arr[],int low,int high)
{
	int pivot,temp,down=low,up=high;
	pivot=arr[low];
	while(down<up)
	{
		while(arr[down]<=pivot && down<high)
			down++;
		while(arr[up]>pivot)
			up--;
		if(down<up)
		{	temp=arr[down];
			arr[down]=arr[up];
			arr[up]=temp;
		}
	}
	arr[low]=arr[up];
	arr[up]=pivot;
	return up;
}

void qsort(int arr[],int low,int high)
{
	int pos;
	if(low>=high)
		return;
	pos=partition(arr,low,high);
		//printf("\npos: %d low: %d high: %d\n",pos,low,high);
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}
int findKsmall(int arr[],int k,int low,int high)
{
	int pos=0;
	if(low>high)   return -1;
	pos=partition(arr,low,high);
	printf("\npos: %d low: %d high: %d k: %d\n",pos,low,high,k);
	if( pos == (low+k-1) )
		return arr[pos];
	if( pos < (low+k-1) )
		return	findKsmall(arr,k-1-pos,pos+1,high);
	else
		return  findKsmall(arr,k,low,pos-1);
}
int main()
{
	int arr[100]={111,14,3,67,90,21,32,55,67,71,83},size=0,i=0,k=0;
    size = 11;
	scanf("%d",&k);
	printf("The %d smallest element of the array is : %d\n",k,findKsmall(arr,k,0,size-1));
	i=0;
	qsort(arr,0,size-1);
	printf("\nThe sorted array is :-\n");
	while(i<size)
	{	printf("  %d",arr[i]);
		i++;
	}
}
