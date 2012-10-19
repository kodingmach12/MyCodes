#include<stdio.h>
#include<stdlib.h>
int lis( int arr[], int n )
{
   int *lis, i, j, max = 0,k,maxpos=0;
   lis = (int*) malloc ( sizeof(int)*n );
   for ( i = 0; i < n; i++ )
      lis[i] = 1;

   for ( i = 1; i < n; i++ )
   {
	for ( j = 0; j < i; j++ )
         if ( arr[j] < arr[i] && lis[i] < (lis[j] + 1) )
            lis[i] = lis[j] + 1;
	//for(k=0;k<n;k++)
		//printf("   %d",lis[k]);
	}
    printf("\n");
   for ( i = 0; i < n; i++ )
   {
       printf("   %d",lis[i]);
      if ( max < lis[i] ) {
         max = lis[i];
         maxpos=i;        }
   }

    printf("\n %d",arr[maxpos]);
    for(i=maxpos-1;i>=0;i--)
    {
        if(arr[i] < arr[maxpos] &&  lis[i]+1 == lis[maxpos] )
        {
            printf(" %d",arr[i]);
            maxpos=i;
        }
    }
   free( lis );
 return max;
}
int main()
{
	//int arr[10]={ 10, 1, 12, 3, 4, 15, 6, 7 ,5,4 },i;
	int arr[8]={ 1, 3, 2, 4, 3, 5, 4, 6 },i;
	int n = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n;i++)
		printf("   %d",arr[i]);
 	printf("\nLength of LIS is %d\n", lis( arr, n ) );
  getchar();
  return 0;
}
