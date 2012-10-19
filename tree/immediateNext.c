#include<stdio.h>


int immediateNext(Node *root,const int k)
{
    if(!root)
        return  -1;
    if(root->data==k)
    {
        return inorder_succ(root);
    }
    if(k < root->data)
    {
        return immediateNext(root->left,k);
    }
    if(k > root->data)
    {
        return immediateNext(root->right,k);
    }

}
