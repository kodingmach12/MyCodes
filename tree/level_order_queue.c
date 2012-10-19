#include<stdio.h>
#include<malloc.h>
typedef struct node{
    struct node *left,*right;
    int data;
}Node;
typedef struct queue{
    Node* tnode;
    struct queue * next;
}Que;
void enqueue(Que **front,Que** rear,Node *t)
{
Que* temp=(Que *)malloc(sizeof(Que));
    if(temp!=NULL)
    {   temp->tnode=t;
        temp->next=NULL;
        (*rear)->next=temp;
        (*rear)=temp;
        if((*front)==NULL)
            *front=temp;
    }
}
Node* dequeue(Que **front,Que **rear)
{
    if(front==NULL)
        return NULL;

    Node* t=(Node *)malloc(sizeof(Que));
    t=(*front)->tnode;
    Que *temp=*front;
    if(front==rear)
    {   front=NULL;
        rear=NULL;
    }
    *front=(*front)->next;

    free(temp);
return t;
}

int isempty(Que *q,Que* front,Que* rear)
{
return (front==NULL && front==rear);
}
Que* initQue(Que **front,Que **rear,Node *tree)
{
    Que* t=(Que *)malloc(sizeof(Que));
    t->tnode=tree;
    t->next=NULL;
    *front=*rear=t;
return t;
}
void printLevelOrder(Node *root)
{
    Node *n=NULL;
    if(root==NULL)
        return;

    Que *q=NULL,*front=NULL,*rear=NULL;

    q=initQue(&front,&rear,root);
    while(!isempty(q,front,rear))
    {
        n=dequeue(&front,&rear);
        printf("    %d",n->data);
        printf("\n");
        if(n->left)
            enqueue(&front,&rear,n->left);
        if(n->right)
            enqueue(&front,&rear,n->right);
    }

}
Node* newNode(int n)
{
    Node *temp=(Node*)malloc(sizeof(Node));
if(temp!=NULL)
{
     temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
}
return temp;
}

int main()
{
    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(6);
    printLevelOrder(root);

return 0;
}

