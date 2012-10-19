#include<stdio.h>
int arr[100]={0},size=0;
void findmean(int num)
{
int i=0,j=0;
	while(num>arr[i] && i<size-1)
		i++;
	if(i==size-1)
		arr[size-1]=num;
	else
	{	for(j=size;j<i;j--)
			arr[j]=arr[j-1];
	arr[j]=num;
	}
/*if((size+1)%2==0)
	return  ((arr[size/2]+arr[size/2+1])/2);
else
	return arr[size/2];
	*/
}

void insertasc(int num)
{
	if(size==0)
	{
		arr[0]=num;
		size++;
	}
	else
	{
		int i=size-1;
		while(arr[i]>num && i>0)
		{
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=num;
		size++;
	}
}


int main()
{
int num,i;
while(1)
{
	scanf("%d",&num);
//	findmean(num);
	insertasc(num);
	printf("->");
	for(i=0;i<10;i++)
		printf(" %d",arr[i]);
	
	//printf("\nThe current median is %d",findmean(num,size));
}


}

