// return values
//  0 - success
//  1- node found, successor not found
//  2- node not found
// Worst case time complexity - > O(n)

int preOrder_Succ(Node *root,Node *p,Node **succ)
{
    if(!root)   return 2;
    if(root==p)
    {
        if(root->left)
        {
            *succ=root->left;
            return 0;
        }
        if(root->right)
        {
            *succ=root->right;
            return 0;
        }
        return 1;  // Node found but successor not found
    }
    int retval=0;
    if(root->left)
    {
        retval = preOrder_Succ(root->left,p,succ);
        if(retval==0)    return 0;
        if(retval==1)
        {
            if(root->right)
            {
                *succ=root->right;
                return 0;
            }
        return 0;
        }
    }
    if(root->right)
    {
        return preOrder_Succ(root->right,p,succ);
    }
return 2;
}
