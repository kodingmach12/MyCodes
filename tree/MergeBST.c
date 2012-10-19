#include<stdio.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}Node;
Node* mergeBST(Node *t1,Node *t2)
{
    if(!t1 && !t2)  return NULL;
    Node *t=NULL;
    if(!t1) return t2;
    if(!t2) return t1;
    t1=Tree2List(t1);
    t2=Tree2List(t2);
    t=MergeList(t1,t2);

    t=MakeTree4mList(t);
return t;
}
