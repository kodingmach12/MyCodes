#include<stdio.h>
typedef struct node
{   struct node* left;
        int data;
	struct node* right;
}node;
int countNodes(Node *t1)
{
    if(t1)
        return 1+countNodes(t1->left)+countNodes(t1->right);
    return 0;
}
int isIdentical(Node *t1, Node *t2)
{
    if( !t1 && !t2 )  return 1;
    if( !t1 || !t2 )  return 0;
    if((t1->data == t2->data) && isIdentical(t1->left,t2->left) && isIdentical(t1->right,t2->right) )
        return 1;
return 0;
}
int count_new(Node *t1, Node *t2, int *flag, int t2_count,Node *subtree_root)
{
    if(!t1) return 0;
    int lcnt=0,rcnt=0,rootcnt=0;
    if(!(*flag))
    {
        lcnt=count_new(t1->left,t2,flag,t2_count,subtree_root);
        if( lcnt == t2_count )
            *flag=isIdentical(t1->left,t2);
        if(*flag)
            subtree_root=t1->left;
    }

    if(!(*flag))
    {
        rcnt=count_new(t1->right,t2,flag,t2_count,subtree_root);
        if( rcnt == t2_count )
            *flag=isIdentical(t1->right,t2);
        if(*flag)
            subtree_root=t1->right;
    }
    if(*flag)
    {   rootcnt=1+lcnt+rcnt;
        if(rootcnt=t2_count)
        {
            *flag=isIdentical(t1,t2);
            if(*flag)
                subtree_root=t1;
        }
    }
return rootcnt;
}
int is_subtree_opt(Node *t1, Node *t2)
{

    if( !t1 && !t2 )  return 1;
    if( !t1 || !t2 )  return 0;
    Node *subtree_root=NULL;
    int flag=0;
    int t2_count= countNodes(t2);
    count_new(t1,t2,t2_count,&flag,subtree_root);
    if(flag)    return 1;
return 0;
}

