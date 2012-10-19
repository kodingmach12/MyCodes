#include<stdio.h>
typedef struct node
{
    struct node *left;
    int data;
    int tnode;
    struct node *right;
}Node;


Node* newNode(int k)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=k;
    temp->tnode=0;
    temp->left=NULL;
    temp->right=NULL;
}
void insert(Node** root,int k)
{
    if(*root==NULL)
    {
        (*root)=newNode(k);
    }
    else
    {

    }
}
Node* findKth(Node* root,int k)
{
    if(!root|| k <=0 || k > root->tnode+1)
        return NULL;
    int lcnt=0,rcnt=0;
    if(root->left)
        lcnt=root->left->tnode+1;
    if(root->right)
        rcnt=root->right->tnode+1;
    if(lcnt==k-1)
        return root;
    else if( k > lcnt+1)
        return findKth(root->right,k-lcnt-1);
    else if( k < lcnt)
        return findKth(root->left,k);
}
int main()
{


return 0;
}
