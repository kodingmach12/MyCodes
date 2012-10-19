#include<stdio.h>
/*
5
45 23 34 12 56
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
void findsum(int arr[],int size,int *a,int *b,int sum)
{
int low=0,high=size-1,temp_sum=0;
int k;
printf("function in");
    while(low<=high)
    {
        k=(arr[low]+arr[high]);
        printf("\n%d",k);
        if(k==sum)
        {
            *a=arr[low];
            *b=arr[high];
            return;
        }
        if( k<sum)
            low++;
        else
            high--;

    }
    printf("Sum not found");
}

int main()
{
	int arr[100],size,i=0;
	int a=0,b=0,s;
    scanf("%d",&size);
	while(i<size)
	{	scanf("%d",&arr[i]);
		i++;
	}
	i=0;
	//while(i<size)
//	{	printf("  %d",arr[i]);
	//	i++;
	//}
//	printf(" <-- input ends here\n");
	qsort(arr,0,size-1);
	i=0;
//	while(i<size)
	//{	printf("  %d",arr[i]);
	//	i++;
//	}


	printf("Enter the sum required\n");
	scanf("%d",&s);
	findsum(arr,size,&a,&b,s);
	printf("\nThe elements are %d %d which sums to %d",a,b,s);
}

