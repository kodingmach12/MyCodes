bool hasPathSum( Node* root, int N ) 
{
	if(NULL==root)
	return (0==N);

	N -= root->data;
	if( hasPathSum( root->left, N ) || hasPathSum( root->right, N ) )
		return true;
	return false;
}
