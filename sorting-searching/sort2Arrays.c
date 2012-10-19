#include<stdio.h>
void sort2arr(int arr1[],int arr2[],int size1,int size2)
{
int i=size1-1,j=size2-size1-1,k=size2-1,temp;
	for(j,i,k;i>0,j>0,k>0;)
	{
		if(arr2[j]>arr1[i])
			arr2[k--]=arr2[j--];
		else
			arr2[k--]=arr1[i--];
	}
		
	if(i>=0)
	{
		while(i!=-1)
			arr2[k--]=arr1[i--];
	}
	
}
int main()
{
int arr1[]={1,3,5,7,9};
int arr2[]={2,4,6,8,10,0,0,0,0,0};
sort2arr(arr1,arr2,5,10);
int i=0;
for(i=0;i<10;i++)
	printf("  %d",arr2[i]);
return 0;
}
