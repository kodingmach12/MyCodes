#include<stdio.h>
typedef struct node
{   struct node* left;
        int data;
	struct node* right;
}node;
int is_subtree(node* t1,node* t2)
{
    if(t1==NULL)
        return 1;
    if(t2==NULL)
        return 0;
    if(t1->data==t2->data)
        return is_subtree(t1->left,t2->left) && is_subtree(t1->right,t2->right);
    else
        return (is_subtree(t1->left,t2)||is_subtree(t1->right,t2));
return 0;
}
