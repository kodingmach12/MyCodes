#include<stdio.h>
//#define toint(char c) ('c'-97)
int partition(char *arr,int low,int high)
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

void qsort(char *arr,int low,int high)
{
	int pos;
	if(low>=high)
		return;
	pos=partition(arr,low,high);
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}
void find_dup(char *arr)
{
	int i=0;
	char *tmp=arr;
		while(*tmp!='\0')
		{
		if(*tmp!=*(tmp+1))
			tmp++;
		else
		{
			printf("\nDuplicate found at position : %d",tmp-arr+1);
			tmp++;
			while(*tmp==*(tmp+1))
				tmp++;
		}
		}
}
int main()
{
	char arr[100],*tmp=arr;
	int size,i=0;
	scanf("%s",&arr);

	while(*tmp!='\0')
	{	//printf("\n %c  %d",arr[i],arr[i]);
		i++;
		tmp++;
	}
	size=i;
	printf("\n input ends here and size is %d\n",size);
	qsort(arr,0,size-1);
	printf("The sorted string is %s\n",arr);
	find_dup(arr);

}
