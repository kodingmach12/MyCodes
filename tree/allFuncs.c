#include<stdio.h>
#define my_sizeof(a) (size_t)( (char*)(&(a)+1) - (char*)(&(a)) )
typedef struct node
{
struct node *left;
int data;
struct node *right;
struct node *in_succ;
}Node;

int ** alloc2d(int row,int col)
{
int i=0;
int **ptr=NULL;
int **ptr=(int**)malloc(row * sizeof(int*));
for(i=0;i<row;i++)
	ptr[i]=(int*)malloc(col * sizeof(int));
return ptr;
}

void getTwoNonRepeating(int arr[],int size,int *n1,int *n2)
{
if(size<0)
	return;
int xor=0,i,xor1=0,xor2=0;
for(i=0;i<size;i++)
	xor=xor^arr[i];
int right_bit_set = xor & ~xor;
for(i=0;i<size;i++)
{
if(arr[i]&xor==0)
	xor1^=arr[i];
else
	xor2^=arr[i];
}

*n1=xor1;
*n2=xor2;
}



int findElementEqualsIndex(int arr[],int size)
{
	//Assumption:-Sorted in increasing order  && array doesn't contain duplicates
	if(size<=0)	return -1;	//if array doesn't contain any elements
	if(a[0] >=size)	return -1; //if first element is greater than size,all elements r greater than
									//index

    int lo=0,hi=size-1,mid;
    while(lo<=hi)
    {
    mid=lo+(hi-lo)>>2;
    if(a[mid]>=size)	return -1;
	if(a[mid]==mid)	return mid;
	else if(a[mid]<mid)	lo=mid+1;
	else	hi=mid-1;
    }
return -1;
}






