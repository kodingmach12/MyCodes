// return values
//  0 - success
//  1- node found, successor not found
//  2- node not found
// Worst case time complexity - > O(n)

int postOrder_Succ(Node *root,Node *p,Node **succ)
{
    if(!root)
        return 2;
    if(root==p)
        return 1;
    Node *temp=NULL;
    int retval=0;
    if(root->left)
    {
        retval=postOrder_Succ(root->left,p,succ);
        if(retval==0)
            return 0;
        if(retval==1)
        {
            if(root->right)
            {
                temp=root->right;
                while(temp->left)
                    temp=temp->left;
                *succ=temp;
            }
            else
                *succ=root;
            return 0;
        }
    }
    if(root->right)
    {
        retval=postOrder_Succ(root->right,p,succ);
        if(retval==0)
            return 0;
        if(retval==1)
        {
            *succ=root;
            return 0;
        }
    }
return 2;
}