#include<stdio.h>


void Compute(int n) 
{
int arr[n];
arr[0]= 1;
int count_2 = 0;
int count_5 = 0;
int i;
for(i = 0;i<=n ; i++)
{
if(2 * arr[count_2] <= 5 * arr[count_5])
{
arr[i] = 2 * arr[count_2];
count_2 ++;
} 
else 
{
arr[i] = 5 * arr[count_5];
count_5 ++; 
}
printf(" %d ", arr[i]);
i++;
}
}

int main()
{
int n;
scanf("%d",&n);
Compute(n);

return 0;
}
