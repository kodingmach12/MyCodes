#include<stdio.h>
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
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}
int main()
{
	int arr[100],size,i=0;
	scanf("%d",&size);
	while(i<size)
	{	scanf("%d",&arr[i]);
		i++;
	}
	i=0;
	while(i<size)
	{	printf("  %d",arr[i]);
		i++;
	}
	printf(" <-- input ends here\n");
	qsort(arr,0,size-1);
	i=0;
	while(i<size)
	{	printf("  %d",arr[i]);
		i++;
	}
}
