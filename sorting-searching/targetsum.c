#include<stdio.h>
/*
7
12 23 34 45 56 67 78
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
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}
void findnum(int arr[],int size,int find)
{
	int lb=0,ub=size-1;
	while(lb<ub)
	{	int sum=arr[lb]+arr[ub];
		if(sum==find)
		{
			printf("\nThe two numbers are %d & %d which adds to %d \n",arr[lb],arr[ub],find);
		return;
		}
		if(sum<find)
			lb++;
		else
			 ub--;

	}
	printf("\nSum not found \n");
	return;
}
int main()
{
	int arr[100],size,i=0,find=0,n1=0,n2=0;
	scanf("%d",&size);
	while(i<size)
	{	scanf("%d",&arr[i]);
		i++;
	}
	i=0;
	qsort(arr,0,size-1);
 	printf("Enter the number to find -->");
	scanf("%d",&find);
	findnum(arr,size,find);
	
}
