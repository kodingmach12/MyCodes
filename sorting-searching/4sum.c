#include<stdio.h>
/*Input
1 2 3 4 10 9 8 7 5 6 

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
void findSum(int a[],int n,int sum)
{
	int in,fin,left,right,temp;
	in=0;
	fin=n-1;
	while(in<fin)
	{
		left=in+1;
		right=fin-1;
		temp=sum-(a[in]+a[fin]);	//we have to search for temp
		while(left<right)
		{
			if(a[left]+a[right]>temp)
				right--;
			else if(a[left]+a[right]<temp)
				left++;
			else
			{
				printf("\n%d  %d  %d  %d\n\n",a[in],a[left],a[right],a[fin]);
				return;
			}
		}
		if(sum>a[in]+a[in+1]+a[fin]+a[fin-1])
			in++;
		else
			fin--;
	}
	printf("\nNot Found\n");
}
int main()
{
	int arr[100],size=11,i=0,sum=0;
	//scanf("%d",&size);
	printf("Input 10 numbers \n");
	while(i<size)
	{	scanf("%d",&arr[i]);
		i++;
	}
	qsort(arr,0,size-1);
	i=0;
	while(i<size)
	{	printf("  %d",arr[i]);
		i++;
	}	
	scanf("%d",&sum);
	findSum(arr,size-1,sum);
	i=0;
	while(i<size)
	{	printf("  %d",arr[i]);
		i++;
	}	
	return 0;
}
