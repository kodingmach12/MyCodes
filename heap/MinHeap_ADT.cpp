#include<iostream>
#include<cstdio>
using namespace std;
class MinHeap
{
   int* harr;
   int heap_size;
 public:
   // constructor
   MinHeap(int a[], int size);
    // to heapify a subtree with root at given index
   void MinHeapify(int index );
   // return the left child of given node
   int left(int  i){  return 2*i+1;  }
   // return the right child of given node
   int right(int i){  return 2*i+2;  }
   // return the min element with given element and return the min element
   int replaceMin(int x);
   // extract the min element, no replacement
   int extractMin();
};

MinHeap::MinHeap(int a[], int size)
{
    harr = a;
    heap_size = size;
    int i = (heap_size-1)/2;
    while(i>0){
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin()
{
    int root = harr[0];
    if(heap_size > 1)
    {
        harr[0]=harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
    }
    return harr[0];
}

int MinHeap::replaceMin(int x)
{
    int root = harr[0];
    harr[0]=x;
    if( x > root )
        MinHeapify(0);
    return root;
}
void MinHeap::MinHeapify(int root)
{
    int l,r;
    l = left(root);
    r = right(root);
    int smallest = root;
    if( l<heap_size && harr[l]<harr[smallest])
        smallest = l;
    if( r<heap_size && harr[r]<harr[smallest])
        smallest = r;
    if(smallest!=root){
        swap(harr[smallest],harr[root]);
        MinHeapify(smallest);
    }
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

// Driver program to test above functions
int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    MinHeap hp(arr,n);
    printf("The min element of heap is %d\n",hp.extractMin());
    printf("Following is sorted array\n");
    printArray (arr, n);

    return 0;
}

