#include<stdio.h>
#define p(n)    printf("n");
void siftDown(int arr[], int root, int bottom)
{
  int maxChild = root * 2 + 1;
// Find the biggest child
  if(maxChild < bottom)
  {
    int otherChild = maxChild + 1;
    // Reversed for stability
    maxChild = (arr[otherChild] > arr[maxChild])?otherChild:maxChild;
  }
  else
  {
    if(maxChild > bottom) return;         // Don't overflow
  }
  // If we have the correct ordering, we are done.
  if(arr[root] >= arr[maxChild]) return;
  // Swap
  int temp = arr[root];
  arr[root] = arr[maxChild];
  arr[maxChild] = temp;

  // Tail queue recursion. Will be compiled as a loop with correct compiler switches.
  siftDown(arr, maxChild, bottom);
}

void heapsort(int arr[], int array_size)
{
  int i, temp;
  for (i = (array_size / 2); i >= 0; i--)
    siftDown(arr, i, array_size - 1);			//Heapify

  for (i = array_size-1; i >= 1; i--)
  {
    // Swap
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    siftDown(arr, 0, i-1);
  }
}


int main()
{
    int a[100],n,i=0;
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&a[i++]);
    }
    heapsort(a,n);
    i=0;
    while(i<n)
    {
        printf(" %d ",a[i++]);
    }

return 0;
}
