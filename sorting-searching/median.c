#include<stdio.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}Node;
Node *maxheap=NULL,*minheap=NULL;
typedef struct info
{
 int maxcnt,mincnt;
}heapinfo;


void insert2heap(Node *root,int data)
{


}

int findmedian(int data)
{
    if(info->maxcnt==info->mincnt)
    {
         insert2heap(Node *maxheap,int data);
         info->maxcnt++;
        return (maxheap->data);
    }
    else if(info->maxcnt==info->mincnt+1)   // remove 1 element from maxheap and insert into minheap
    {
           insert2heap(Node *minheap,int data);
           info->mincnt++;
           return (maxheap->data + minheap->data)/2 ;
    }

}


int main()
{

return 0;
}
