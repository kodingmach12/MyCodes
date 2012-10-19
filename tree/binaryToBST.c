btree* max_tree(btree *root)
{
	if(root == NULL)
		return root;
	btree * current = root;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}
btree * min_tree(btree *root)
{
	if(root == NULL)
		return root;
	btree * current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
void binarytreetobst(btree *root)
{
//base-case tree is empty
	if(root == NULL)
		return;
	else if(root->left == NULL && root->right == NULL) //base-case tree of size 1
		return;
	else
	{
		binarytreetobst(root->left);
		binarytreetobst(root->right);

		btree* max = max_tree(root->left);
		if(max && max->data > root->data)
		{
			int temp = root->data;
			root->data = max->data;
			max->data = temp;
			binarytreetobst(root->left);

		}
		btree* min = min_tree(root->right);
		if(min && min->data  < root->data)
		{
			int temp = root->data;
			root->data = min->data;
			min->data = temp;
			binarytreetobst(root->right);
		}
	}
}

Node* FindKth(Node *root,int k)
{
    if(k==0 || root==NULL || k<0 || (k > root->nodecount+1) )
        return NULL;

    if(k==1 && root->left==NULL && root->right==NULL)
        return root->data;
    if(k == root->left->nodecount+1)
        return root->data;
    if(k > root->nodecount)
    {
        findNode(root->left,);
    }

}
