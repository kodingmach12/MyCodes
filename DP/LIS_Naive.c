#include<stdio.h>
#include<stdlib.h>
struct result
{
    int lis_len;
    int last_index;};
struct result lis( int arr[], int n )
{
    struct result res, max;
    max.lis_len = 1;
    max.last_index = n-1;
	int i=0;
    if(n == 1)
        return max;
    for(i = 1; i < n; i++)
	{
        res = lis(arr, i);
        if (arr[res.last_index] < arr[n-1])
        {
            res.lis_len++;
            res.last_index = n - 1;
		}
        if(res.lis_len  > max.lis_len)
            max = res;
    }
    return max;
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    struct result max = lis( arr, n );
    printf("Length of LIS is %d\n",  max.lis_len);

    getchar();
    return 0;
}