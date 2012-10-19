#include<stdio.h>
#include<assert.h>
int maxbitonic(int arr[],int n)
{
assert(n>0);
int max,len,i,prev;
i=1;
len=1;
max=1;
prev=0;
while(i<n)
{

if(i>=n)
	return max;
while(arr[i]>=arr[i-1] && i<n)
{	i++;
	len++;
}

if(max<len)
	max=len;

i++;

if(i>=n)
	return max;
prev=i;

while( arr[i] <= arr[i-1] && i<n)
{	i++;
	len++;
}
if(max<len)
	max=len;

if(i>=n)
	return max;
i=prev;
}




}

int main()
{
int  arr[10];
int i=0;
while(i!=10)
	scanf("%d",&arr[i++]);
printf("\t%d\n",maxbitonic(arr,10));


return 0;

}
