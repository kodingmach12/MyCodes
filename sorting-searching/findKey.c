#include<stdio.h>
int findKey(int arr[],int n,int key)
{

  if(key > (arr[0]+n-1)  || key < arr[0]-n+1 )
    return -1;
  int dist=0,i=0;
  while(i<n)
  {
    dist=key-arr[i];
    printf("\n%d   %d",i,dist);
    if(dist<0)
     dist*=-1;
    if(i+dist >=n)
        return -1;
    if(arr[i+dist]==key)
        return (i+dist);
    else
    {
        i+=dist;
    }
  }
return -1;
}
int main()
{
    int arr[100];
    int n=0,i=0;
    scanf("%d",&n);
    while(i<n)
        scanf("%d",&arr[i++]);
    scanf("%d",&i);
    int pos=findKey(arr,n,i);
    printf("\nThe element  %d is at (0-based array) %d\n",arr[pos],pos);

return 0;
}
