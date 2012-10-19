node *find_closest(node *root, int x)
{
    static node *pre = NULL, *suc = NULL;
    node *result = NULL;
    if(root != NULL)
	{
        if(root->data > x)
		{
     //       if(suc == NULL)
       //         suc = root;
         //   else if(suc->data > root->data)
                suc = root;
            result = find_closest(root->left, x);
        }
        else if(root->data < x)
		{
           // if(pre == NULL)
             //   pre = root;
            //else if(pre->data < root->data)
                pre = root;
            result = find_closest(root->right, x);
        }
        else
            result = root;
        if(result == NULL)
		{
            if(pre != NULL && suc != NULL){
                if((x - pre -> data) < (suc -> data - x))
                    result = pre;
                else
                    result = suc;
            }
            else{
                if(pre == NULL)
                    result = suc;
                else
                    result = pre;
            }
        }
            
    }
    
    return result;
}